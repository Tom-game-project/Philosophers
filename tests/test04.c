#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;  // スレッドごとの識別番号
    int *counter;
    pthread_mutex_t *mutex;
} ThreadData;

void *increment(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    // 排他制御でカウンターを安全にインクリメント
    pthread_mutex_lock(data->mutex);
    (*(data->counter))++;
    printf("Thread %d incremented counter to %d\n", data->id, *(data->counter));
    pthread_mutex_unlock(data->mutex);

    free(data); // ヒープに確保したメモリを解放
    return NULL;
}

int main() {
    pthread_t threads[5];
    int counter = 0;
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);

    // スレッドごとに異なるデータを作成
    for (int i = 0; i < 5; i++) {
        ThreadData *data = malloc(sizeof(ThreadData)); // 各スレッド用にデータを動的確保
        data->id = i; // IDを割り振る
        data->counter = &counter;
        data->mutex = &mutex;

        pthread_create(&threads[i], NULL, increment, data);
    }

    // スレッドの終了を待つ
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", counter);

    pthread_mutex_destroy(&mutex);
    return 0;
}

