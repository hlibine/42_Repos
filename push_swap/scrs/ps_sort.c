/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:12:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 14:26:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_sort_b_2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;
	int		a;

	a = ps_lstsize(*stack_a);
	while (a > 3 && !ps_issorted(*stack_a))
	{
		tmp = *stack_a;
		i = ps_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ps_check_rarb(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rarb(stack_a, stack_b, tmp->nbr);
			else if (i == ps_check_rrarrb(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rrarrb(stack_a, stack_b, tmp->nbr);
			else if (i == ps_check_rarrb(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rarrb(stack_a, stack_b, tmp->nbr);
			else if (i == ps_check_rrarb(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rrarb(stack_a, stack_b, tmp->nbr);
			else
				tmp = tmp->next;
		}
		a--;
	}
}

void	ps_clean_3(t_stack **stack_a)
{
	if (ps_lstmin(*stack_a) == (*stack_a)->nbr)
	{
		ps_rra(stack_a, 0);
		ps_sa(stack_a, 0);
	}
	else if (ps_lstmax(*stack_a) == (*stack_a)->nbr)
	{
		ps_ra(stack_a, 0);
		if (!ps_issorted(*stack_a))
			ps_sa(stack_a, 0);
	}
	else
	{
		if (ps_find_index(*stack_a, ps_lstmax(*stack_a)) == 1)
			ps_rra(stack_a, 0);
		else
			ps_sa(stack_a, 0);
	}
}

t_stack	*ps_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ps_lstsize(*stack_a) > 3 && !ps_issorted(*stack_a))
		ps_pb(stack_a, &stack_b, 0);
	if (ps_lstsize(*stack_a) > 3 && !ps_issorted(*stack_a))
		ps_pb(stack_a, &stack_b, 0);
	if (ps_lstsize(*stack_a) > 3 && !ps_issorted(*stack_a))
		ps_sort_b_2(stack_a, &stack_b);
	if (!ps_issorted(*stack_a))
		ps_clean_3(stack_a);
	return (stack_b);
}

t_stack	**ps_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ps_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ps_check_rarb_a(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rarb_a(stack_a, stack_b, tmp->nbr);
			else if (i == ps_check_rarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rarrb_a(stack_a, stack_b, tmp->nbr);
			else if (i == ps_check_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = ps_sort_rrarrb_a(stack_a, stack_b, tmp->nbr);
			else if (i == ps_check_rrarb_a(*stack_a, *stack_b, tmp->nbr))
				i = (ps_sort_rrarb_a(stack_a, stack_b, tmp->nbr));
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	ps_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ps_lstsize(*stack_a) == 2)
		ps_sa(stack_a, 0);
	else
	{
		stack_b = ps_sort_b(stack_a);
		stack_a = ps_sort_a(stack_a, &stack_b);
		i = ps_find_index(*stack_a, ps_lstmin(*stack_a));
		if (i < ps_lstsize(*stack_a) - i)
			while ((*stack_a)->nbr != ps_lstmin(*stack_a))
				ps_ra(stack_a, 0);
		else
			while ((*stack_a)->nbr != ps_lstmin(*stack_a))
				ps_rra(stack_a, 0);
	}
}
