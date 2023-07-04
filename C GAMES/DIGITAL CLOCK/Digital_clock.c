#include <stdio.h>
#include <windows.h>
#include <unistd.h>

int main()
{
    int h, m, s;
    int d = 1; //We add a delay of 1000 milliseconds and we will use it in the function sleep

    printf("Set time: \n");
    scanf("%d %d %d", &h, &m, &s);

    if (h > 12 || m > 60 || s > 60)
    {
        printf("ERROR !\n");
        exit(0);
    }
    while (d) // This is an infinite loop and anythin inside will repeat utself to infinity
    {
        s++;
        if (s > 59)
        {
            m++;
            s = 0;
        }
        if (m > 59)
        {
            h++;
            m = 0;
        }
        if (h > 12)
        {
            h = 1;
        }
        printf("\n Clock : ");
        printf("%02d:%02d:%02d", h, m, s); // This writes our time in this format 00:00:00
        sleep(d); // The function that slows down the while loop and makes it more like a real clock
        system("cls"); // This clears the screen
    }
}