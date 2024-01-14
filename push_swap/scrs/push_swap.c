/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:45:13 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/10 13:01:37 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = ps_lstwrk(argc, argv);
	if (!a || ps_chckdup(a))
		ps_exit();
	if (!(ps_issorted(a)))
		ps_sort(&a);
	ps_free(&a);
	return (0);
}
