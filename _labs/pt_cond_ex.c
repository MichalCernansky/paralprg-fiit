// gcc pt_cond_ex.c -o pt_cond_ex -lpthread

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef enum { NONE, RED, GREEN } color_t;
const int NO_THREADS = 2;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int stop = 0;
color_t color = RED;

void* thread_fnc(void* arg) {
    
    color_t my_color = (color_t)arg;
    
    while (!stop) {
        
        pthread_mutex_lock(&mutex);
        while (color != my_color) pthread_cond_wait(&cond, &mutex);
        color = NONE;
        pthread_mutex_unlock(&mutex);
        
        printf("%s\n", my_color==RED ? "red" : "green");
        sleep(1);
        
        pthread_mutex_lock(&mutex);
        color = my_color==RED ? GREEN : RED;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}

int main(void) {
    
    pthread_t red_threads[NO_THREADS];
    pthread_t green_threads[NO_THREADS];
    
    for (int i=0; i<NO_THREADS; i++) {
        pthread_create(&red_threads[i], NULL, &thread_fnc, (void*) RED);
        pthread_create(&green_threads[i], NULL, &thread_fnc, (void*) GREEN);
    }
    
    sleep(10);
    stop = 1;
    
    for (int i=0; i<NO_THREADS; i++) {
        pthread_join(red_threads[i], NULL);
        pthread_join(green_threads[i], NULL);
    }
    
    return 0;
}
