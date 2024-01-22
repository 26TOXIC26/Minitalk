#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>

// void recieve(int sig)
// {
//     if  (sig == SIGUSR2)
//         printf("recieved");
// }
 
// void write_s()
// {
//     siginfo_t info;
//     kill(info->si_pid,SIGUSR2)
//     // write(1, "ryrha\n", 6);
    
// }

void ft_send_bit(int pid, char *s)
{
    int i;
    int next;

    i = 0;

    while (s[i])
    {
        next = 7;
        while (next >= 0)
        {
            if ((s[i] >> next) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(10);
            next--;
        }
        i++;
    } 
}

int main (int argc, char **argv)
{
    if (argc == 3)
    {
        char    *str;
        int pid;

        pid = ft_atoi(argv[1]);
        str = argv[2];
        ft_send_bit(pid, str);
    }
    else if (argc > 3)
        ft_printf("You are write more than 2 argument");
    else
        ft_printf("You are write less than 2 argument");
}