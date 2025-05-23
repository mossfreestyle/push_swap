/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:32:25 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/17 15:50:00 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	print_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	exit_cleanup(t_stack *stack, char **numbers)
{
	int	i;

	i = 0;
	if (numbers)
	{
		while (numbers[i])
		{
			free(numbers[i]);
			numbers[i] = NULL;
			i++;
		}
		free(numbers);
	}
	exit_error(stack);
}

void	exit_error(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	print_exit();
}
