/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:35:30 by amousaid          #+#    #+#             */
/*   Updated: 2024/01/27 01:03:37 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void	bit(int sig)
{
	static char	char_bit;
	static int	num_bit;

	if (num_bit <= 7)
	{
		char_bit = (char_bit << 1);
		if (sig == SIGUSR1)
			char_bit++;
		num_bit++;
	}
	if (char_bit && num_bit > 7)
	{
		ft_printf("%c", char_bit);
		char_bit = 0;
		num_bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("--------Welcom to my MINITALK--------\n");
	ft_printf("            PID of server  \n               [%d]\n", pid);
	while (1)
	{
		signal(SIGUSR1, bit);
		signal(SIGUSR2, bit);
	}
}
