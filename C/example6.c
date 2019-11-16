#include <pthread.h>

pthread_mutexattr_t m1_attr;
pthread_mutex_t mu1, mu2;

void *Thread1(void *x) {
    pthread_mutex_lock(&mu1);
    pthread_mutex_lock(&mu2);
    pthread_mutex_unlock(&mu2);
    pthread_mutex_unlock(&mu1);
    return NULL;
}

void *Thread2(void *x) {
    pthread_mutex_lock(&mu2);
    pthread_mutex_lock(&mu1);
    pthread_mutex_unlock(&mu1);
    pthread_mutex_unlock(&mu2);
    return NULL;
}



int main() {
    pthread_t t[2];
//    pthread_mutexattr_init(&attributes);
    pthread_mutex_init(&mu1, NULL);
    pthread_mutex_init(&mu2, NULL);
//    pthread_mutexattr_settype(pthread_mutexattr_t * attr);
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_mutex_destroy(&mu1);
    pthread_mutex_destroy(&mu2);
}