/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:03:15 by hlibine           #+#    #+#             */
/*   Updated: 2023/11/06 10:15:02 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_putnbrun(unsigned long int n, char *str, int *p)
{
	unsigned int	i;

	i = ft_strlen(str);
	if (n >= i)
	{
		ft_printf_putnbrun(n / i, str, p);
		ft_printf_putnbrun(n % i, str, p);
	}
	else
		ft_printf_putchar(str[n], p);
}

static void	ft_printf_format(char in, va_list args, int *p)
{
	if (in == 0)
		ft_printf_putstr("(null)", p);
	else if (in == 'c')
		ft_printf_putchar((char)va_arg(args, int), p);
	else if (in == 's')
		ft_printf_putstr(va_arg(args, char *), p);
	else if (in == 'p')
		ft_printf_ptohex(va_arg(args, void *), p);
	else if (in == 'd' || in == 'i')
		ft_printf_putnbr(va_arg(args, int), "0123456789", p);
	else if (in == 'u')
		ft_printf_putnbrun(va_arg(args, unsigned int), "0123456789", p);
	else if (in == 'x')
		ft_printf_putnbr(va_arg(args, int), "0123456789abcdef", p);
	else if (in == 'X')
		ft_printf_putnbr(va_arg(args, int), "0123456789ABCDEF", p);
	else if (in == '%')
		ft_printf_putchar('%', p);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		a;
	int		*p;
	va_list	args;

	i = 0;
	a = 0;
	p = &a;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_format(format[i++], args, p);
		}
		else
			ft_printf_putchar(format[i++], p);
	}
	va_end(args);
	return (a);
}

// int	main(void)
// {
// 	int i;
// 	int a;
// 	//char *str = "hello there %u is %c\n";

// 	i = ft_printf("%x\n", -1);
// 	a = printf("%x\n", -1);

// 	printf("ft_printf return value: %i\n", i);
// 	printf("printf return value: %i\n", a);

// 	ft_printf("%x\n", -42);
// 	ft_printf("%x\n", -42);
// }
