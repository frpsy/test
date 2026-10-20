// Firebase 콘솔 > 프로젝트 설정 > 내 앱(웹)의 firebaseConfig 값을 붙여 넣습니다.
// 같은 Firebase 프로젝트의 다른 페이지(/test/waldorf/ 등)와 함께 쓸 수 있습니다. 웹 설정값은 비밀 키가 아니며, 접근 제어는 firestore.rules가 담당합니다.
// apiKey가 비어 있으면 이 브라우저에만 저장되는 체험(데모) 모드로 동작합니다.
export const FIREBASE_CONFIG = {
    apiKey: '',
    authDomain: '',
    projectId: '',
    storageBucket: '',
    messagingSenderId: '',
    appId: ''
};
