#include <pthread.h>
#include <stdlib.h>

int Global;
pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void lock() {
    pthread_mutex_lock(&mutex);
}

void *Thread1(void *x) {
    pthread_mutex_lock(&mutex);
    Global++;
    pthread_mutex_lock(&mutex);
//    if (pthread_mutex_lock(&mutex) != 0)
//        exit(1);

//    lock();
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *Thread2(void *x) {
    pthread_mutex_lock(&mutex);
    Global--;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t[2];
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_init(&mutex, &attr);

    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_mutex_destroy(&mutex);
}