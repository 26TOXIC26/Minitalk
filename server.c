#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void bit(int sig)
{
    static char char_bit;
    static int  num_bit;

    // num_bit = 0;
    if(num_bit <=  7)
    {   
        char_bit = (char_bit << 1);
        if (sig == SIGUSR1)
            char_bit++;
        num_bit++;
    }
    if(char_bit && num_bit > 7) 
    {
        ft_printf("%c", char_bit);
        num_bit = 0;
        char_bit = 0;
    }
    else
    {
        ft_printf("\n");
        num_bit = 0;
        char_bit = 0;
    }
}


int main(void)
{
    pid_t pid = getpid();
    ft_printf("PID of my server : [%d]", pid );

    while (1) {
        signal(SIGUSR1, bit);
        signal(SIGUSR2, bit);
        // pause();
        // usleep(1); // Sleep for 1 second or do some other work
    }
    return (0);
}