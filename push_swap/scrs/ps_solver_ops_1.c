/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver_ops_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:10:12 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 14:32:09 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_sort_rarb_a(t_stack **stack_a, t_stack **stack_b, int in)
{
	while ((*stack_b)->nbr != in && ps_find_pos_a(*stack_a, in) > 0)
		ps_rr(stack_a, stack_b, 0);
	while ((*stack_b)->nbr != in)
		ps_rb(stack_b, 0);
	while (ps_find_pos_a(*stack_a, in) > 0)
		ps_ra(stack_a, 0);
	ps_pa(stack_a, stack_b, 0);
	return (-1);
}

int	ps_sort_rrarrb_a(t_stack **stack_a, t_stack **stack_b, int in)
{
	while ((*stack_b)->nbr != in && ps_find_pos_b(*stack_b, in) > 0)
		ps_rrr(stack_a, stack_b, 0);
	while ((*stack_b)->nbr != in)
		ps_rrb(stack_b, 0);
	while (ps_find_pos_a(*stack_a, in) > 0)
		ps_rra(stack_a, 0);
	ps_pa(stack_a, stack_b, 0);
	return (-1);
}

int	ps_sort_rarrb_a(t_stack **stack_a, t_stack **stack_b, int in)
{
	while (ps_find_pos_a(*stack_a, in) > 0)
		ps_ra(stack_a, 0);
	while ((*stack_b)->nbr != in)
		ps_rrb(stack_b, 0);
	ps_pa(stack_a, stack_b, 0);
	return (-1);
}

int	ps_sort_rrarb_a(t_stack **stack_a, t_stack **stack_b, int in)
{
	while (ps_find_pos_a(*stack_a, in) > 0)
		ps_rra(stack_a, 0);
	while ((*stack_b)->nbr != in)
		ps_rb(stack_b, 0);
	ps_pa(stack_a, stack_b, 0);
	return (-1);
}
