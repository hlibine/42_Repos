/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:20:40 by rude-jes          #+#    #+#             */
/*   Updated: 2023/07/16 17:53:51 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	output;

	sign = 1;
	output = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (!(str[i] == '+' || str[i] == '-' || str[i] == ' '))
				break ;
			if (str[i] == ' ' && output != 0)
				break ;
		}
		if (str[i] == '-' && output == 0)
			sign = sign * -1;
		else if (str[i] == '-' && output != 0)
			break ;
		else if (str[i] >= '0' && str[i] <= '9')
			output = (output * 10) + str[i] - '0';
		i++;
	}
	return (output * sign);
}

int	main(int argc, char *argv[])
{
	if (argc < 3)
		return (0);
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
