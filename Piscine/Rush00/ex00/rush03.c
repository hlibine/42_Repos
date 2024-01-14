/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:25:08 by rude-jes          #+#    #+#             */
/*   Updated: 2023/07/15 14:54:54 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	pos_y;
	int	pos_x;

	pos_y = 0;
	while (pos_y < y)
	{
		pos_x = 0;
		while (pos_x < x)
		{
			if (pos_x == 0 && (pos_y == 0 || pos_y == y - 1))
				ft_putchar('A');
			else if (pos_x == x - 1 && (pos_y == 0 || pos_y == y - 1))
				ft_putchar('C');
			else if (pos_y == 0 || pos_y == y - 1)
				ft_putchar('B');
			else if (pos_x == 0 || pos_x == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			pos_x++;
		}
		ft_putchar ('\n');
		pos_y++;
	}
}
