#include <pthread.h>

int main() {
    pthread_mutex_t mu1, mu2;
    pthread_mutex_init(&mu1, NULL);
    pthread_mutex_init(&mu2, NULL);

    // mu1 => mu2
    pthread_mutex_lock(&mu1);
    pthread_mutex_lock(&mu2);
    pthread_mutex_unlock(&mu2);
    pthread_mutex_unlock(&mu1);

    // mu2 => mu1
    pthread_mutex_lock(&mu2);
    pthread_mutex_lock(&mu1);  // <<<<<<< OOPS
    pthread_mutex_unlock(&mu1);
    pthread_mutex_unlock(&mu2);

    pthread_mutex_destroy(&mu1);
    pthread_mutex_destroy(&mu2);
}