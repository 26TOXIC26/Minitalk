/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:35:43 by amousaid          #+#    #+#             */
/*   Updated: 2024/01/25 22:40:44 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>

void ft_send_bit(int pid, char *s)
{
    int i;
    int j;
    int next;

    i = 0;
    j = ft_strlen(s);
    while (i <= j)
    {
        next = 7;
        while (next >= 0)
        {
            if ((s[i] >> next) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(9);
            next--;
        }
        i++;
    }
    
}
void write_reply(int signal)
{
    if(signal == SIGUSR1)
        ft_printf("[YOUR MESSAGE IS RECEIVED]\n");
}

int main (int argc, char **argv)
{
    if (argc == 3)
    {
        char    *str;
        int pid;
        
        signal(SIGUSR1, write_reply);
        pid = ft_atoi(argv[1]);
        str = argv[2];
        ft_send_bit(pid, str);
    }
    else if (argc > 3)
        ft_printf("You are write more than 2 argument");
    else
        ft_printf("You are write less than 2 argument");
    
}