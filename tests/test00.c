#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <unistd.h>


void *thread_func(void *param);
void *thread_func_wait_sec(void *param);

int main(void) {
	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;

	useconds_t c = 1000000;
	ret = pthread_create(&thread1, NULL, thread_func_wait_sec, &c);
	if (ret != 0) {
		// pthread_createが失敗した場合は0以外の値を返す
		exit(1);
	}

	// スレッドの作成
	// int pthread_create(pthread_t * thread, pthread_attr_t * attr,
	//                    void * (*start_routine)(void *), void * arg)
	// 第4引数に渡した値が、スレッド関数の引数に渡される
	ret = pthread_create(&thread2, NULL, thread_func, NULL);
	if (ret != 0) {
		// pthread_createが失敗した場合は0以外の値を返す
		exit(1);
	}

	// スレッドの終了を待機
	// int pthread_join(pthread_t th, void **thread_return)
	ret = pthread_join(thread1, NULL);
	if (ret != 0) {
		// pthread_joinが失敗した場合は0以外の値を返す
		exit(1);
	}

	// スレッドの終了を待機
	// int pthread_join(pthread_t th, void **thread_return)
	ret = pthread_join(thread2, NULL);
	if (ret != 0) {
		// pthread_joinが失敗した場合は0以外の値を返す
		exit(1);
	}

	/*
	// スレッドの終了を待たない
	// int pthread_detach(pthread_t th)
	ret = pthread_detach(thread);
	if (ret != 0) {
		// pthread_detachが失敗した場合は0以外の値を返す
		exit(1);
	}
	*/
	return EXIT_SUCCESS;
}

void *thread_func(void *param)
{
	// 非同期に実行する処理
	(void) param;
	printf("hello world\n");
	return (NULL);
}

void *thread_func_wait_sec(void *param)
{
	useconds_t *sec = (useconds_t *)param;

	printf("proc start\n");
	usleep(*sec);
	printf("hello world %d\n", *sec);
	return (NULL);
}


