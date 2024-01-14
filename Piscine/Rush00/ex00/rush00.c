/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:25:08 by rude-jes          #+#    #+#             */
/*   Updated: 2023/07/15 14:55:03 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

// because rush() exceeded the 25 lines for norminette
void	print(int pos_y, int pos_x, int y, int x)
{
	if (pos_y == 0 && pos_x == 0)
		ft_putchar('o');
	else if (pos_y == y - 1 && pos_x == x - 1)
		ft_putchar('o');
	else if (pos_y == 0 && pos_x == x - 1)
		ft_putchar('o');
	else if (pos_y == y - 1 && pos_x == 0)
		ft_putchar('o');
	else if (pos_y == 0 || pos_y == y - 1)
		ft_putchar('-');
	else if (pos_x == 0 || pos_x == x - 1)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

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
			print(pos_y, pos_x, y, x);
			pos_x++;
		}
		ft_putchar ('\n');
		pos_y++;
	}
}
