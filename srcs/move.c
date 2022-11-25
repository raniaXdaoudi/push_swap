/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:04:28 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 19:20:31 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char const *move)
{
	int	tmp;

	if (stack)
	{
		tmp = stack->next->val;
		stack->next->val = stack->val;
		stack->val = tmp;
		ft_printf("%s\n", move);
	}
}

void	ft_push(t_stack **stack_src, t_stack **stack_dest, char *move)
{
	t_stack	*tmp;

	if (stack_src)
	{
		tmp = (*stack_src)->next;
		(*stack_src)->next = *stack_dest;
		*stack_dest = *stack_src;
		*stack_src = tmp;
		ft_printf("%s\n", move);
	}
}

void	ft_rotate(t_stack **stack, char *move)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = NULL;
	if (stack && *stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tail = ft_stack_last(*stack);
		tmp->next = NULL;
		tail->next = tmp;
		ft_printf("%s\n", move);
	}
}

void	ft_reverse_rotate(t_stack **stack, char *move)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*new_last;

	if (stack && *stack)
	{
		last = ft_stack_last(*stack);
		tmp = *stack;
		while ((*stack) && ((*stack)->next->next != NULL))
			(*stack) = (*stack)->next;
		new_last = *stack;
		*stack = last;
		(*stack)->next = tmp;
		new_last->next = NULL;
		ft_printf("%s\n", move);
	}
}
