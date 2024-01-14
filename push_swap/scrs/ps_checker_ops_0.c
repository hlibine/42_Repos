/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_ops_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:33:36 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 15:59:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_check_rarb(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = ps_find_pos_b(stack_b, in);
	if (i < ps_find_index(stack_a, in))
		i = ps_find_index(stack_a, in);
	return (i);
}

int	ps_check_rrarrb(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;
	int	lsta_s;
	int	lstb_s;

	i = 0;
	lsta_s = ps_lstsize(stack_a);
	lstb_s = ps_lstsize(stack_b);
	if (ps_find_pos_b(stack_b, in))
	i = lstb_s - ps_find_pos_b(stack_b, in);
	if ((i < (lsta_s - ps_find_index(stack_a, in)))
		&& ps_find_index(stack_a, in))
		i = lsta_s - ps_find_index(stack_a, in);
	return (i);
}

int	ps_check_rrarb(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = 0;
	if (ps_find_index(stack_a, in))
		i = ps_lstsize(stack_a) - ps_find_index(stack_a, in);
	i += ps_find_pos_b(stack_b, in);
	return (i);
}

int	ps_check_rarrb(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = 0;
	if (ps_find_pos_b(stack_b, in))
		i = ps_lstsize(stack_b) - ps_find_pos_b(stack_b, in);
	i += ps_find_index(stack_a, in);
	return (i);
}

int	ps_rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_a;
	i = INT_MAX;
	while (tmp)
	{
		if (i > ps_check_rarb(stack_a, stack_b, tmp->nbr))
			i = ps_check_rarb(stack_a, stack_b, tmp->nbr);
		if (i > ps_check_rrarb(stack_a, stack_b, tmp->nbr))
			i = ps_check_rrarb(stack_a, stack_b, tmp->nbr);
		if (i > ps_check_rarrb(stack_a, stack_b, tmp->nbr))
			i = ps_check_rarrb(stack_a, stack_b, tmp->nbr);
		if (i > ps_check_rrarrb(stack_a, stack_b, tmp->nbr))
			i = ps_check_rrarrb(stack_a, stack_b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
