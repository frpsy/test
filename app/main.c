#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int counter = 0;      // 공유 변수
pthread_mutex_t lock; // 뮤텍스 선언

void *thread_func(void *arg)
{
    int thread_id = *(int *)arg;

    // 뮤텍스 잠금
    pthread_mutex_lock(&lock);

    int local = counter;
    printf("Thread %d sees counter = %d\n", thread_id, local);
    counter = local + 1;

    // 뮤텍스 해제
    pthread_mutex_unlock(&lock);

    free(arg);
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    // 뮤텍스 초기화
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        perror("pthread_mutex_init");
        return 1;
    }

    // 스레드 생성
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i + 1;
        if (pthread_create(&threads[i], NULL, thread_func, thread_id) != 0)
        {
            perror("pthread_create");
            return 1;
        }
    }

    // 스레드 종료 대기
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    // 뮤텍스 파괴
    pthread_mutex_destroy(&lock);

    printf("Final counter = %d\n", counter);
    return 0;
}
