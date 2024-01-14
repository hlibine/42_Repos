/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_ops_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:08:15 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 14:27:43 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = ps_find_pos_a(stack_a, in);
	if (i < ps_find_index(stack_b, in))
		i = ps_find_index(stack_b, in);
	return (i);
}

int	ps_check_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = 0;
	if (ps_find_pos_a(stack_a, in))
		i = ps_lstsize(stack_a) - ps_find_pos_a(stack_a, in);
	if ((i < (ps_lstsize(stack_b) - ps_find_index(stack_b, in)))
		&& ps_find_index(stack_b, in))
		i = ps_lstsize(stack_b) - ps_find_index(stack_b, in);
	return (i);
}

int	ps_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = 0;
	if (ps_find_index(stack_b, in))
		i = ps_lstsize(stack_b) - ps_find_index(stack_b, in);
	i += ps_find_pos_a(stack_a, in);
	return (i);
}

int	ps_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int in)
{
	int	i;

	i = 0;
	if (ps_find_pos_a(stack_a, in))
		i = ps_lstsize(stack_a) - ps_find_pos_a(stack_a, in);
	i += ps_find_index(stack_b, in);
	return (i);
}

int	ps_rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_b;
	i = INT_MAX;
	while (tmp)
	{
		if (i > ps_check_rarb_a(stack_a, stack_b, tmp->nbr))
			i = ps_check_rarb_a(stack_a, stack_b, tmp->nbr);
		if (i > ps_check_rrarb_a(stack_a, stack_b, tmp->nbr))
			i = ps_check_rrarb_a(stack_a, stack_b, tmp->nbr);
		if (i > ps_check_rarrb_a(stack_a, stack_b, tmp->nbr))
			i = ps_check_rarrb_a(stack_a, stack_b, tmp->nbr);
		if (i > ps_check_rrarrb_a(stack_a, stack_b, tmp->nbr))
			i = ps_check_rrarrb_a(stack_a, stack_b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
