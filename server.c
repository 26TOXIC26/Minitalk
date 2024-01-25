/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:35:30 by amousaid          #+#    #+#             */
/*   Updated: 2024/01/25 22:14:13 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void bit(int sig, siginfo_t *info, void *context)
{
    static char char_bit;
    static int  num_bit;

    (void)context;

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
        char_bit = 0;
        num_bit = 0;
    }
    else if (char_bit == '\0' && num_bit > 7)
    {
        kill(info->si_pid ,SIGUSR1);     
        char_bit = 0;
        num_bit = 0;
    }
}


int main()
{
    pid_t pid;
    struct sigaction sa;

    sa.sa_sigaction = bit;
    sa.sa_flags = SA_SIGINFO;
    pid = getpid();
    ft_printf("PID of my server : [%d]\n", pid);
    
    while (1) 
    {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
    }
}