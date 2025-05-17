/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:01:19 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 10:23:57 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

void    free_stack(t_stack *stack)
{
	t_stack *tmp;
	
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void    print_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void    exit_cleanup(t_stack *stack, char **nbr)
{
	int i;

	i = 0;
	if (nbr)
	{
		while (nbr[i])
		{
			free(nbr[i]);
			nbr[i] = NULL;
			i++;
		}
		free(nbr);
	}
	exit_error(stack);
}

void    exit_error(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	print_exit();
}