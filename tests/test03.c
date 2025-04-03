#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *counter;
    pthread_mutex_t *mutex;
} ThreadData;

void *increment(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    // 排他制御でカウンターを安全にインクリメント
    pthread_mutex_lock(data->mutex);
    (*(data->counter))++;
    pthread_mutex_unlock(data->mutex);

    return NULL;
}

int main() {
    pthread_t threads[5];
    int counter = 0;
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);

    // スレッドごとにデータ構造体を作成
    ThreadData data = {&counter, &mutex};

    // スレッドを作成し、データを渡す
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, increment, &data);
    }

    // スレッドの終了を待つ
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", counter);

    pthread_mutex_destroy(&mutex);
    return 0;
}

