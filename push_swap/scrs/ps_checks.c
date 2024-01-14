/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:08 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 15:55:02 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_isnumeric(const char *in)
{
	if (*in <= 47 || *in >= 58)
		return (0);
	in++;
	while (*in)
	{
		if (*in <= 47 || *in >= 58)
			return (0);
		in++;
	}
	return (1);
}

int	ps_chckdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	ps_issorted(t_stack *list)
{
	int	temp;

	temp = list->nbr;
	while (list)
	{
		if (list->nbr < temp)
			return (0);
		temp = list->nbr;
		list = list->next;
	}
	return (1);
}
