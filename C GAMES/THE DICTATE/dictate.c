#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char buffer[] = "Hello, my name is Gabriel. Have we met before?\nWas also wondering where you are from.\nGuess we'll never know!!!";

    for (int i = 0; i <= sizeof(buffer) - 1; i++)
    {
        printf("%c", buffer[i]);
        usleep(100000);
    }
    sleep(10);
    return(0);
}