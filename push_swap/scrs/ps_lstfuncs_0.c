/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstfuncs_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:31:48 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/04 16:06:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ps_find_index(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->nbr != num)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	ps_lstmin(t_stack *lst)
{
	int	min;

	min = lst->nbr;
	lst = lst->next;
	while (lst)
	{
		if (min > lst->nbr)
			min = lst->nbr;
		lst = lst->next;
	}
	return (min);
}

int	ps_lstmax(t_stack *lst)
{
	int	max;

	max = lst->nbr;
	lst = lst->next;
	while (lst)
	{
		if (max < lst->nbr)
			max = lst->nbr;
		lst = lst->next;
	}
	return (max);
}
