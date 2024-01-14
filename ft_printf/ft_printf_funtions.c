/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funtions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:45:50 by hlibine           #+#    #+#             */
/*   Updated: 2023/11/06 10:15:26 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(char c, int *p)
{
	write(1, &c, 1);
	*p += 1;
}

void	ft_printf_putstr(char *str, int *p)
{
	int	i;
	int	a;

	if (!str)
	{
		ft_printf_putstr("(null)", p);
		return ;
	}
	i = ft_strlen(str);
	*p += i;
	a = 0;
	while (a < i)
		write(1, &str[a++], 1);
}

void	ft_printf_putnbr(int n, char *str, int *p)
{
	unsigned int	nu;
	size_t			i;

	if (!str)
		return ;
	nu = n;
	i = ft_strlen(str);
	if (n < 0 && i != 16)
	{
		ft_printf_putchar('-', p);
		nu = -n;
	}
	if (nu >= i)
	{
		ft_printf_putnbr(nu / i, str, p);
		ft_printf_putnbr(nu % i, str, p);
	}
	else
		ft_printf_putchar(str[nu], p);
}

void	ft_printf_ptohex(void *p, int *o)
{
	int	i;

	i = 0;
	ft_printf_putstr("0x", o);
	ft_printf_putnbrun((unsigned long int)p, "0123456789abcdef", o);
}
