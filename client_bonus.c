/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:58:08 by amousaid          #+#    #+#             */
/*   Updated: 2024/01/29 01:41:25 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <signal.h>

int	ft_check_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_send_bit(int pid, char *s)
{
	int	i;
	int	j;
	int	next;
	int	pid_check;

	i = 0;
	j = ft_strlen(s);
	while (i <= j)
	{
		next = 7;
		while (next >= 0)
		{
			if ((s[i] >> next) & 1)
				pid_check = kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(9);
			next--;
		}
		i++;
	}
	if (pid_check == -1)
		ft_printf("[PID IS WRONG]\n");
}

void	write_reply(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("[YOUR MESSAGE IS RECEIVED]\n");
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc == 3)
	{
		if (ft_check_pid(argv[1]) == 0)
			return (ft_printf("3mrk chfti chi pid fih 7orof \n"));
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
