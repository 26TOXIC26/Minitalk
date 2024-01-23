/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaid <mousaid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:35:25 by amousaid          #+#    #+#             */
/*   Updated: 2023/12/01 00:28:11 by mousaid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_l(int n, int *sum)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_l('-', sum);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_l(nb / 10, sum);
		ft_putnbr_l(nb % 10, sum);
	}
	else
		ft_putchar_l(nb + 48, sum);
}
