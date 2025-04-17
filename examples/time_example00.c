#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(void) {
    struct timeval start, end;

    gettimeofday(&start, NULL);

    // 適当な処理
    //for (volatile int i = 0; i < 100000000; ++i);
    usleep(3000);

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    useconds_t elapsed = seconds * 1000 + microseconds * 1e-3;

    printf("処理時間: %d ミリ秒\n", elapsed);

    return 0;
}

