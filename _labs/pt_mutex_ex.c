// gcc pt_mutex_ex.c -o pt_mutex_ex -lpthread

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;

void* thread_func(void* ptr)
{
    long i;
    printf("Thread %ld started.\n", (long)ptr);

    for (i=0; i<10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %ld ended.\n", (long)ptr);
    return ptr;
}

int main()
{
    long i, ret;
    pthread_t threads[10];

    for (i=0; i<10; i++) pthread_create(&threads[i], NULL, thread_func, (void*)i);

    for (i=0; i<10; i++) {
        pthread_join(threads[i], (void*)&ret);
        printf("Thread %ld joined.\n", ret);
    }
    
    printf("Counter is %d.\n", counter);
    
    return 0;
}
