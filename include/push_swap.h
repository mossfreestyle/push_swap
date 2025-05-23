/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:52:23 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 16:12:44 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

const char	*trim_whitespace(const char *str);
t_stack		*init_stack(int ac, char **av);
t_stack		*stack_new_node(int content);
t_stack		*stack_get_last(t_stack *lst);
void		stack_add_top(t_stack **lst, t_stack *new_node);
void		free_stack(t_stack *stack);
void		exit_error(t_stack *stack);
void		exit_cleanup(t_stack *stack, char **numbers);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		sort_stack(t_stack **stack_a);
void		advanced_sort(t_stack **a, t_stack **b);
void		rotate_to_min(t_stack **a);
int			is_sorted(t_stack *stack);
int			parse_arg(const char *str, int *error);
int			stack_size(t_stack *stack);
int			max_value(t_stack *stack);
int			min_value(t_stack *stack);
int			calculate_cost(t_stack *a, t_stack *b, int value);
int			rotation_cost(int size, int pos);
int			ft_abs(int num);
int			find_position(t_stack *b, int value);
int			find_index(t_stack *stack, int value);

#endif