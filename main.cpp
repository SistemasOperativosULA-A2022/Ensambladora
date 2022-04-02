#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static phtread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
static phtread_cond_t count_cv;

int main()
{
    phtread_t thread;

    return 0;
}