/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrossell <rrossell@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:31:41 by rrossell          #+#    #+#             */
/*   Updated: 2023/07/23 22:31:45 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

int	char_to_int(char c)
{
	int	num;

	if (c >= '0' && c <= '4')
		num = c - '0';
	else
		return (-1);
	return (num);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_line(int line[], int reversed[4])
{
	int	counter;

	counter = 0;
	while (counter < 4)
	{
		reversed[counter] = line[4 - counter -1];
		counter++;
	}
}

void	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		write(1, &str[counter], 1);
		counter++;
	}
}
