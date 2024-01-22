/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaid <mousaid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:48:33 by amousaid          #+#    #+#             */
/*   Updated: 2023/12/01 00:27:35 by mousaid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_l(unsigned int n, int *sum)
{
	long	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_putunbr_l(nb / 10, sum);
		ft_putunbr_l(nb % 10, sum);
	}
	else
		ft_putchar_l(nb + 48, sum);
}
