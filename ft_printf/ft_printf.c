/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaid <mousaid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:40:29 by amousaid          #+#    #+#             */
/*   Updated: 2023/12/01 00:24:38 by mousaid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_format(char format, va_list arg, int *sum)
{
	void	*p;

	if (format == 'c')
		ft_putchar_l((va_arg(arg, int)), sum);
	else if (format == 's')
		ft_putstr_l((va_arg(arg, char *)), sum);
	else if (format == 'd' || format == 'i')
		ft_putnbr_l((va_arg(arg, int)), sum);
	else if (format == 'x' || format == 'X')
		ft_puthex_l((va_arg(arg, unsigned int)), format, sum);
	else if (format == 'u')
		ft_putunbr_l((va_arg(arg, unsigned int)), sum);
	else if (format == '%')
		ft_putchar_l('%', sum);
	else if (format == 'p')
	{
		p = va_arg(arg, void *);
		if (p == NULL)
			ft_putstr_l("(nil)", sum);
		else
		{
			ft_putstr_l("0x", sum);
			ft_puthex_l((long long)p, 'x', sum);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		sum;
	int		i;

	va_start(arg, format);
	sum = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_print_format(format[++i], arg, &sum);
		else
			ft_putchar_l(format[i], &sum);
		i++;
	}
	va_end(arg);
	return (sum);
}

// #include <stdio.h>

// // Your custom printf implementation

// int main() {
//     int num = -42;
//     char ch = 'A';
//     const char *str = "Hello, World!";
//     int x;
//     // Original printf
//     printf("Original printf:");
//     printf("\n");
//     x = printf("Integer: %u", num);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x =printf("Character: %c", ch);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf("String: %s", str);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf("Hexadecimal: %x", num);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf("Hexadecimal: %X", num);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x= printf("adresse:  %p", NULL);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");

//     // ft_printf

//     printf("\nTesting ft_printf:");
//     printf("\n");
//     x = ft_printf("Integer: %u", num);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x =ft_printf("Character: %c", ch);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf("String: %s", str);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf("Hexadecimal: %x", num);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf("Hexadecimal: %X", num);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x= ft_printf("adresse:  %p", NULL);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");

//     return (0);
// }
// int main()
// {
//     int x;
// x = printf(" NULL %s NULL ", NULL);
// printf("\n");
// printf("%d " , x);
// printf("\n");
// x = ft_printf(" NULL %s NULL ", NULL);
// printf("\n");
// printf("%d " , x);
// printf("\n");
// printf(" %x \n", LONG_MIN);
// ft_printf("%x  \n", LONG_MIN);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p ", 1);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p ", 15);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p ", 16);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p ", 17);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p %p ", LONG_MIN, LONG_MAX);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p %p ", INT_MIN, INT_MAX);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     printf("\n");
//     printf("\n");
//     printf("\n");
//     printf("\n");
//        x = ft_printf(" %p ", -1);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p ", 1);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p ", 15);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p ", 16);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p ", 17);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p %p ", INT_MIN, INT_MAX);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");
//     x = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
//     printf("\n");
//     printf("%d " , x);
//     printf("\n");

// }
