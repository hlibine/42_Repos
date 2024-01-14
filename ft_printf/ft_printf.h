/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:11:10 by hlibine           #+#    #+#             */
/*   Updated: 2023/11/06 10:15:32 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

void	ft_printf_putnbr(int n, char *str, int *p);
void	ft_printf_ptohex(void *p, int *o);
void	ft_printf_putchar(char c, int *p);
void	ft_printf_putstr(char *str, int *p);
void	ft_printf_putnbrun(unsigned long int n, char *str, int *p);
int		ft_printf(const char *format, ...);

#endif