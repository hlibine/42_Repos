/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:45:24 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/08 13:10:23 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	ps_rra(stack_a, 1);
	ps_rrb(stack_b, 1);
	if (flag == 0)
		write(1, "rrr\n", 4);
}
