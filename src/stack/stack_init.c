/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:56:12 by rwassim           #+#    #+#             */
/*   Updated: 2025/05/17 10:24:05 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static int  has_duplicate(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int  add_nbr_to_stack(t_stack **stack, const char *str)
{
	int value;
	int error;
	t_stack *new_node;

	error = 0;
	value = parse_arg(str, &error);
	if (error || has_duplicate(*stack, value))
		return (-1);
	new_node = stack_new_node(value);
	if (!new_node)
		return (-1);
	stack_add_top(stack, new_node);
	return (0);
}

static void fill_stack_from_string(t_stack **stack, char *str)
{
	char    **nbr;
	int i;

	nbr = ft_split(str, ' ');
	if (!nbr)
		exit_error(*stack);
	i = 0;
	while (nbr[i] != NULL)
		i++;
	while (i > 0)
	{
		i--;
		if (add_nbr_to_stack(stack, nbr[i] == -1))
		{
			free(nbr[i]);
			nbr[i] = NULL;
			exit_cleanup(*stack, nbr);
		}
		free(nbr[i]);
	}
	free(nbr);
}

t_stack *init_stack(int ac, char **av)
{
	t_stack *stack;
	int i;
	
	stack = NULL;
	if (ac == 2)
	{
		if (av[1] == NULL || trim_whitespace(av[1]) == '\0')
			exit_error(stack);
		fill_stack_from_string(&stack, av[1]);
	}
	else
	{
		i = ac - 1;
		while (i > 0)
		{
			if (add_nbr_to_stack(&stack, av[i]) == -1)
				exit_error(stack);
			i--;
		}
	}
	return (stack);
}