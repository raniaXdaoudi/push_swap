/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 21:04:28 by rania             #+#    #+#             */
/*   Updated: 2022/10/16 19:53:07 by rania            ###   ########.fr       */
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
		tmp = stack->next->pos;
		stack->next->pos = stack->pos;
		stack->pos = tmp;
		ft_printf("%s\n", move);
	}
}

void	ft_push(t_stack **stack_src, t_stack **stack_dest, char *move)
{
	t_stack	*tmp;

	if (stack_src)
	{
		tmp = ft_stack_new((*stack_src)->val, (*stack_src)->pos);
		ft_stack_add_front(stack_dest, tmp);
		(*stack_src) = (*stack_src)->next;
		ft_printf("%s\n", move);
	}
}

void	ft_rotate(t_stack **stack, char *move)
{
	t_stack	*tmp;

	tmp = NULL;
	if (stack && *stack)
	{
		tmp = ft_stack_new((*stack)->val, (*stack)->pos);
		ft_stack_add_back(stack, tmp);
		(*stack) = (*stack)->next;
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
