#include <pthread.h>

pthread_mutex_t mutex;

void *Thread1(void *x) {
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t t;
    pthread_create(&t, NULL, Thread1, NULL);
    pthread_join(t, NULL);
    pthread_mutex_destroy(&mutex);
}