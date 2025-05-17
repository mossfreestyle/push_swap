/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:41:11 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 10:23:42 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void push(t_stack **src_stack, t_stack **dest_stack)
{
	t_stack *first;

	if (src_stack == NULL || *src_stack == NULL)
		return ;
	first = *src_stack;
	*src_stack = first->next;
	first->next = *dest_stack;
	*dest_stack = first;
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}