/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstfuncs_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:31:16 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/04 14:09:03 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}

int	ps_find_pos_b(t_stack *stack_b, int num)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num > stack_b->nbr && num < ps_lstlast(stack_b)->nbr)
		i = 0;
	else if (num > ps_lstmax(stack_b) || num < ps_lstmin(stack_b))
		i = ps_find_index(stack_b, ps_lstmax(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < num || tmp->nbr > num)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ps_find_pos_a(t_stack *stack_a, int num)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (num < stack_a->nbr && num > ps_lstlast(stack_a)->nbr)
		i = 0;
	else if (num > ps_lstmax(stack_a) || num < ps_lstmin(stack_a))
		i = ps_find_index(stack_a, ps_lstmin(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > num || tmp->nbr < num)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
