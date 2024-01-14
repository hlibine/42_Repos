/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:29:32 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/08 13:35:11 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_ra(t_stack **stack_a, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	last = ps_lstlast(*stack_a);
	last->next = tmp;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	ps_rb(t_stack **stack_b, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	last = ps_lstlast(*stack_b);
	last->next = tmp;
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	ps_rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	ps_ra(stack_a, 1);
	ps_rb(stack_b, 1);
	if (flag == 0)
		write(1, "rr\n", 3);
}

void	ps_rra(t_stack **stack_a, int flag)
{
	t_stack	*last;
	t_stack	*b4last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next != NULL)
	{
		b4last = last;
		last = last->next;
	}
	b4last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	ps_rrb(t_stack **stack_b, int flag)
{
	t_stack	*last;
	t_stack	*b4last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next != NULL)
	{
		b4last = last;
		last = last->next;
	}
	b4last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (flag == 0)
		write(1, "rrb\n", 4);
}
