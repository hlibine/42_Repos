/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:53:41 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/10 13:01:06 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_check_rrx(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		ps_rra(stack_a, 1);
	else if (line[2] == 'b')
		ps_rrb(stack_b, 1);
	else if (line[2] == 'r')
		ps_rrr(stack_a, stack_b, 1);
}

char	*ps_check_cmds(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ps_sa(stack_a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ps_sb(stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ps_pa(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ps_pb(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ps_ra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ps_rb(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] != '\n')
		ps_check_rrx(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ps_rr(stack_a, stack_b, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ps_ss(stack_a, stack_b, 0);
	else
		ps_exit();
	return (get_next_line(0));
}

void	ps_checker_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ps_check_cmds(stack_a, stack_b, line);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!ps_issorted(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = ps_lstwrk(argc, argv);
	if (!stack_a || ps_chckdup(stack_a))
		ps_exit();
	stack_b = NULL;
	line = get_next_line(0);
	if (!line && !ps_issorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && ps_issorted(stack_a))
		write(1, "OK\n", 3);
	else
		ps_checker_op(&stack_a, &stack_b, line);
	ps_free(&stack_a);
	ps_free(&stack_b);
	return (0);
}
