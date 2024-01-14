/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstwrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:02:50 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/10 14:25:07 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstadd_back(t_stack **stack, t_stack *new)
{
	if (!*stack)
		*stack = new;
	else
		ps_lstlast(*stack)->next = new;
	return ;
}

t_stack	*ps_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

// Custom more compact atoi that checks for non numeric values
int	ps_atoi(const char *str)
{
	int				n;
	long long int	i;

	i = 0;
	n = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		n *= -1;
		str++;
	}
	if (*str == '+')
		str++;
	if (!(ps_isnumeric(str)))
		ps_exit();
	while (*str)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((n * i) > INT_MAX || (n * i) < INT_MIN)
		ps_exit();
	return (n * i);
}

t_stack	*ps_splitwrk(const char *argv)
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		b;

	a = NULL;
	i = 0;
	temp = ft_split(argv, 32);
	if (!temp)
		ps_exit();
	while (temp[i])
	{
		b = ps_atoi(temp[i]);
		ps_lstadd_back(&a, ps_lstnew(b));
		free(temp[i]);
		i++;
	}
	free(temp);
	return (a);
}

t_stack	*ps_lstwrk(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		b;

	a = NULL;
	i = 1;
	if (argc < 2 && !argv[1])
		exit(1);
	if (argc == 2)
		a = ps_splitwrk(argv[1]);
	else
	{
		while (i < argc)
		{
			b = ps_atoi(argv[i]);
			ps_lstadd_back(&a, ps_lstnew(b));
			i++;
		}
	}
	return (a);
}
