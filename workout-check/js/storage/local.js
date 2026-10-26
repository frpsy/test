// 브라우저 저장소(localStorage) 어댑터. GitHub Pages 등 단독 실행용.

const KEY = 'workout-check:v2';
const LEGACY_KEY = 'wk-state'; // v1 단일 파일 버전

function probe() {
  try {
    const k = '__wc_probe__';
    localStorage.setItem(k, '1');
    localStorage.removeItem(k);
    return true;
  } catch {
    return false;
  }
}

function read() {
  try {
    const s = localStorage.getItem(KEY);
    if (s) return JSON.parse(s);
    const legacy = localStorage.getItem(LEGACY_KEY);
    if (legacy) {
      const o = JSON.parse(legacy);
      return { config: o.cfg || null, days: o.days || {} };
    }
  } catch {
    /* 손상된 데이터는 무시하고 새로 시작 */
  }
  return null;
}

export function createLocalAdapter() {
  const available = probe();
  const loaded = read();
  const data = { config: (loaded && loaded.config) || null, days: (loaded && loaded.days) || {} };

  function write() {
    if (!available) return;
    localStorage.setItem(KEY, JSON.stringify(data));
  }

  return {
    kind: 'local',
    synced: false,
    canDownload: true,
    label: available
      ? '이 브라우저에만 저장됩니다. 다른 기기로 옮기려면 백업을 쓰세요.'
      : '이 브라우저는 저장을 막고 있어 새로고침하면 기록이 사라집니다.',

    subscribe({ onConfig, onDays }) {
      onConfig(data.config);
      onDays({ ...data.days });
      // 같은 브라우저의 다른 탭에서 바꾼 내용 반영
      const onStorage = (e) => {
        if (e.key !== KEY || !e.newValue) return;
        try {
          const next = JSON.parse(e.newValue);
          data.config = next.config || null;
          data.days = next.days || {};
          onConfig(data.config);
          onDays({ ...data.days });
        } catch {
          /* 무시 */
        }
      };
      window.addEventListener('storage', onStorage);
      return () => window.removeEventListener('storage', onStorage);
    },

    async saveConfig(doc) {
      data.config = doc;
      write();
    },

    async saveDay(date, doc) {
      data.days[date] = doc;
      write();
    },
  };
}
