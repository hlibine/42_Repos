/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:28:08 by hlibine           #+#    #+#             */
/*   Updated: 2024/01/09 16:24:49 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "Libft/libft.h"
# include <unistd.h>
# include "bonus/get_next_line/get_next_line.h"

typedef struct s_list
{
	int				nbr;
	int				index;
	struct s_list	*next;
}	t_stack;

t_stack	*ps_lstnew(int content);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
void	ps_lstadd_back(t_stack **stack, t_stack *new);
t_stack	*ps_lstwrk(int argc, char **argv);
int		ps_lstsize(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);
int		ps_find_index(t_stack *stack, int num);
int		ps_lstmin(t_stack *lst);
int		ps_lstmax(t_stack *lst);
int		ps_isnumeric(const char *in);
int		ps_issorted(t_stack *list);
int		ps_chckdup(t_stack *a);
void	ps_sort(t_stack **stack_a);
void	ps_exit(void);
void	ps_free(t_stack **stack);
void	ps_sa(t_stack **stack_a, int flag);
void	ps_sb(t_stack **stack_b, int flag);
void	ps_ss(t_stack **stack_a, t_stack **stack_b, int flag);
void	ps_pa(t_stack **stack_a, t_stack **stack_b, int flag);
void	ps_pb(t_stack **stack_a, t_stack **stack_b, int flag);
void	ps_ra(t_stack **stack_a, int flag);
void	ps_rb(t_stack **stack_b, int flag);
void	ps_rr(t_stack **stack_a, t_stack **stack_b, int flag);
void	ps_rra(t_stack **stack_a, int flag);
void	ps_rrb(t_stack **stack_b, int flag);
void	ps_rrr(t_stack **stack_a, t_stack **stack_b, int flag);
int		ps_find_pos_b(t_stack *stack_b, int num);
int		ps_find_pos_a(t_stack *stack_a, int num);
int		ps_check_rarb(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rrarrb(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rrarb(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rarrb(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int in);
int		ps_rotate_type_ab(t_stack *stack_a, t_stack *stack_b);
int		ps_rotate_type_ba(t_stack *stack_a, t_stack *stack_b);
int		ps_sort_rarb(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rrarrb(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rarrb(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rrarb(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rarb_a(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rrarrb_a(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rarrb_a(t_stack **stack_a, t_stack **stack_b, int in);
int		ps_sort_rrarb_a(t_stack **stack_a, t_stack **stack_b, int in);

#endif