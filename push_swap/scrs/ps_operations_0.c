/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:34:23 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/08 13:35:31 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_sa(t_stack **stack_a, int flag)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	ps_sb(t_stack **stack_b, int flag)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ps_ss(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	ps_sa(stack_a, 1);
	ps_sb(stack_b, 1);
	if (flag == 0)
		write(1, "ss\n", 3);
}

void	ps_pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	t_stack	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	ps_pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	t_stack	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (flag == 0)
		write(1, "pb\n", 3);
}
