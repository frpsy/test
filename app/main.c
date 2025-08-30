// app/main.c

#include <stdio.h>
#include <pthread.h>

void *print_message(void *arg)
{
    char *message = (char *)arg;
    printf("Thread says: %s\n", message);
    return NULL;
}

int main()
{
    pthread_t thread;
    const char *msg = "Hello from a thread!";

    // 스레드 생성
    if (pthread_create(&thread, NULL, print_message, (void *)msg) != 0)
    {
        perror("pthread_create failed");
        return 1;
    }

    // 메인 스레드는 여기서 기다림
    pthread_join(thread, NULL);

    printf("Main thread done.\n");
    return 0;
}
