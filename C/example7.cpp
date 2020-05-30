#include <pthread.h>
#include <chrono>
#include <iostream>


pthread_mutex_t mu1, mu2, mu3, mu4, mu5;

//#define SIZE 10000
//#define SIZE 100000
//#define SIZE 1000000
//#define SIZE 10000000
#define SIZE 100000000

void *Thread1(void *x) {
    for (int i = 0; i < SIZE; ++i) {
        pthread_mutex_lock(&mu1);
        pthread_mutex_lock(&mu2);
        pthread_mutex_unlock(&mu2);
        pthread_mutex_unlock(&mu1);
    }
    return NULL;
}

void *Thread2(void *x) {
    for (int i = 0; i < SIZE; ++i) {
        pthread_mutex_lock(&mu3);
        pthread_mutex_lock(&mu4);
        pthread_mutex_lock(&mu5);
        pthread_mutex_unlock(&mu5);
        pthread_mutex_unlock(&mu4);
        pthread_mutex_unlock(&mu3);
    }
    return NULL;
}

void *Thread3(void *x) {
    for (int i = 0; i < SIZE; ++i) {
        pthread_mutex_lock(&mu3);
        pthread_mutex_lock(&mu5);
        pthread_mutex_lock(&mu4);
        pthread_mutex_unlock(&mu4);
        pthread_mutex_unlock(&mu5);
        pthread_mutex_unlock(&mu3);
    }
    return NULL;
}

int main() {
    auto t1 = std::chrono::steady_clock::now();
    pthread_t t[3];
    pthread_mutex_init(&mu1, NULL);
    pthread_mutex_init(&mu2, NULL);
    pthread_mutex_init(&mu3, NULL);
    pthread_mutex_init(&mu4, NULL);
    pthread_mutex_init(&mu5, NULL);
    pthread_create(&t[0], NULL, Thread1, NULL);
    pthread_create(&t[1], NULL, Thread2, NULL);
    pthread_create(&t[2], NULL, Thread3, NULL);
    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);
    pthread_join(t[2], NULL);
    pthread_mutex_destroy(&mu1);
    pthread_mutex_destroy(&mu2);
    pthread_mutex_destroy(&mu3);
    pthread_mutex_destroy(&mu4);
    pthread_mutex_destroy(&mu5);
    auto t2 = std::chrono::steady_clock::now();
    std::cout << "Size: " << SIZE << std::endl;
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count() << std::endl;
}