#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *arg)
{
    int thread_num = *(int *)arg;
    printf("Hello from thread 2 %d\n", thread_num);
    free(arg); // 동적 할당 해제
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        int *thread_num = malloc(sizeof(int)); // 고유 번호를 위한 동적 메모리
        *thread_num = i + 1;

        if (pthread_create(&threads[i], NULL, print_message, thread_num) != 0)
        {
            perror("pthread_create failed");
            return 1;
        }
    }

    // 모든 스레드 종료 대기
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Main thread done.\n");
    return 0;
}
