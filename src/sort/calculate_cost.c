/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:14:24 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 12:15:13 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int	find_position(t_stack *b, int value)
{
    t_stack	*tmp;
    int	pos;

	tmp = b;
	pos = 0;
    if (value > max_value(b) || value < min_value(b))
    {
        pos = find_index(b, max_value(b)) + 1;
        if (pos == stack_size(b))
            pos = 0;
    }
    else
    {
        while (!(b->value < value && value < b->next->value))
        {
            b = b->next;
            pos++;
        }
        pos++;
    }
    return (pos);
}

static int	rotate_cost(int *cost_a, int *cost_b)
{
	int	total;

	total = 0;
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		total++;
	}
	return (total);
}

static int	reverse_rotate_cost(int *cost_a, int *cost_b)
{
	int	total;

	total = 0;
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		total++;
	}
	return (total);
}

static int	combined_rotation_cost(int cost_a, int cost_b)
{
	int	total_cost;

	total_cost = 0;
	if (cost_a > 0 && cost_b > 0)
	{
		total_cost = rotate_cost(&cost_a, &cost_b);
		total_cost += cost_a + cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		total_cost = reverse_rotate_cost(&cost_a, &cost_b);
		total_cost += ft_abs(cost_a) + ft_abs(cost_b);
	}
	else
		total_cost = ft_abs(cost_a) + ft_abs(cost_b);
	return (total_cost);
}

int	calculate_cost(t_stack *a, t_stack *b, int value)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	pos_a = find_index(a, value);
	pos_b = find_position(b, value);
	cost_a = rotate_cost(stack_size(a), pos_a);
	cost_b = rotate_cost(stack_size(b), pos_b);
	return (combined_rotation_cost(cost_a, cost_b));	
}