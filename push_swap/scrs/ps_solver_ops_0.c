/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver_ops_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:20:58 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 14:47:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_sort_rarb(t_stack **stack_a, t_stack **stack_b, int in)
{
	while ((*stack_a)->nbr != in && ps_find_pos_b(*stack_b, in) > 0)
		ps_rr(stack_a, stack_b, 0);
	while ((*stack_a)->nbr != in)
		ps_ra(stack_a, 0);
	while (ps_find_pos_b(*stack_b, in) > 0)
		ps_rb(stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	return (-1);
}

int	ps_sort_rrarrb(t_stack **stack_a, t_stack **stack_b, int in)
{
	while ((*stack_a)->nbr != in && ps_find_pos_b(*stack_b, in) > 0)
		ps_rrr(stack_a, stack_b, 0);
	while ((*stack_a)->nbr != in)
		ps_rra(stack_a, 0);
	while (ps_find_pos_b(*stack_b, in) > 0)
		ps_rrb(stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	return (-1);
}

int	ps_sort_rarrb(t_stack **stack_a, t_stack **stack_b, int in)
{
	while ((*stack_a)->nbr != in)
		ps_ra(stack_a, 0);
	while (ps_find_pos_b(*stack_b, in) > 0)
		ps_rrb(stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	return (-1);
}

int	ps_sort_rrarb(t_stack **stack_a, t_stack **stack_b, int in)
{
	while ((*stack_a)->nbr != in)
		ps_rra(stack_a, 0);
	while (ps_find_pos_b(*stack_b, in) > 0)
		ps_rb(stack_b, 0);
	ps_pb(stack_a, stack_b, 0);
	return (-1);
}
