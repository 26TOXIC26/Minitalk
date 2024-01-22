/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaid <mousaid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:14:58 by amousaid          #+#    #+#             */
/*   Updated: 2023/12/01 00:25:55 by mousaid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_l(size_t nb, char format, int *sum)
{
	char	*hex;

	if (format == 'x')
		hex = "0123456789abcdef";
	else if (format == 'X')
		hex = "0123456789ABCDEF";
	if (nb < 16)
		ft_putchar_l(hex[nb % 16], sum);
	else
	{
		ft_puthex_l(nb / 16, format, sum);
		ft_putchar_l(hex[nb % 16], sum);
	}
}
