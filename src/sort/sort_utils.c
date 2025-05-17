/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:41:30 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 10:22:42 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

int ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int rotation_cost(int size, int pos)
{
	int forward;
	int reverse;

	forward = pos;
	reverse = size - pos;
	if (forward <= reverse)
		return (forward);
	else
		return (-reverse);
}

int find_index(t_stack *stack, int value)
{
	int i;

	i = 0;
	while (stack->value != value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int max_value(t_stack *stack)
{
	int max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int min_value(t_stack *stack)
{
	int min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}