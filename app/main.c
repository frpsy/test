#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

int turn = 1;         // 현재 차례 (1번 스레드부터 시작)
pthread_mutex_t lock; // 뮤텍스
pthread_cond_t cond;  // 조건 변수

void *thread_func(void *arg)
{
    int thread_id = *(int *)arg;
    free(arg);

    pthread_mutex_lock(&lock);

    // 자기 차례가 될 때까지 기다림
    while (thread_id != turn)
    {
        pthread_cond_wait(&cond, &lock);
    }

    // 실행
    printf("Thread %d is running\n", thread_id);

    // 다음 차례로 넘김
    turn++;
    pthread_cond_broadcast(&cond); // 대기 중인 모든 스레드를 깨움

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // 스레드 생성
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i + 1;
        pthread_create(&threads[i], NULL, thread_func, thread_id);
    }

    // 스레드 종료 대기
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&lock);

    printf("All threads done.\n");
    return 0;
}
