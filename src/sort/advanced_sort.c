/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:27:03 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 10:56:43 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

void	push_to_b(t_stack **a, t_stack **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		pb(a, b);
		count++;
	}
	if (is_sorted(*b))
		rb(b);
}

t_stack	*find_elem(t_stack *a, t_stack *b)
{
	t_stack	*min_cost_elem;
	t_stack	*current;
	int	min_cost;
	int	cost;

	min_cost_elem = NULL;
	min_cost = INT_MAX;
	current = a;
	while (current)
	{
		cost = calculate_cost(a, b, current->value);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_elem = current;
		}
		current = current->next;
	}
	return (min_cost);
}

void	single_stack_rotation(t_stack **stack, int rotation, bool is_forward, bool is_stack_a)
{
	while (rotation > 0)
	{
		if (is_forward)
		{
			if (is_stack_a)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (is_stack_a)
				rra(stack);
			else
				rrb(stack);
		}
		rotation--;
	}
}

void	perform_rotation(t_stack **stack_a, int a_cost, t_stack **stack_b, int b_cost)
{
	if (a_cost > 0 && b_cost > 0)
	{
		while (a_cost > 0 && b_cost > 0)
		{
			rr(stack_a, stack_b);
			a_cost--;
			b_cost--;
		}
	}
	else if (a_cost < 0 && b_cost < 0)
	{
		while (a_cost < 0 && b_cost < 0)
		{
			rrr(stack_a, stack_b);
			a_cost++;
			b_cost++;
		}
	}
	single_stack_rotation(stack_a, ft_abs(a_cost), (a_cost >= 0), true);
	single_stack_rotation(stack_b, ft_abs(b_cost), (b_cost >= 0), false);
}

void	advanced_sort(t_stack **a, t_stack **b)
{
	t_stack	*min_cost;
	int	pos_in_a;
	int	pos_in_b;
	int	cost_a;
	int	cost_b;

	push_to_b(a,b);
	while (*a)
	{
		min_cost = find_elem(*a, *b);
		pos_in_a = find_index(*a, min_cost->value);
		pos_in_b = find_index(*b, min_cost->value);
		cost_a = rotation_cost(stack_size(*a), pos_in_a);
		cost_b = rotation_cost(stack_size(*b), pos_in_b);
		perform_rotation(a, cost_a, b, cost_b);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
	rotate_to_min(a);
}