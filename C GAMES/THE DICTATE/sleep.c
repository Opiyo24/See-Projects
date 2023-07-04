#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec sleepTime;
    sleepTime.tv_sec = 1; //1 second
    sleepTime.tv_nsec = 500000000; //500 million nanoseconds (0.5 seconds)

    int result = nanosleep(&sleepTime, NULL);
    if (result == 0)
    {
        printf("Sleep completed\n");
    }
    else
    {
        printf("Sleep interrupted, remaining time: %ld seconds, %ld nanoseconds\n", sleepTime.tv_sec, sleepTime.tv_nsec);
    }
    return(0);
}