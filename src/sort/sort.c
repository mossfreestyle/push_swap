/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:19:11 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/17 15:49:50 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < third && second > third)
	{
		sa(a);
		ra(a);
	}
}

void	rotate_to_min(t_stack **a)
{
	int	min_val;
	int	pos_in_a;
	int	size;

	min_val = min_value(*a);
	pos_in_a = find_index(*a, min_val);
	size = stack_size(*a);
	if (pos_in_a <= size / 2)
	{
		while ((*a)->value != min_val)
			ra(a);
	}
	else
	{
		while ((*a)->value != min_val)
			rra(a);
	}
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		rotate_to_min(a);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size <= 5)
		simple_sort(stack_a, &stack_b);
	else
		advanced_sort(stack_a, &stack_b);
	free_stack(stack_b);
}
