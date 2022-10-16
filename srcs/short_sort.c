/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:55 by rania             #+#    #+#             */
/*   Updated: 2022/10/03 15:56:33 by rania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->val;
	b = (*stack)->next->val;
	c = (*stack)->next->next->val;
	if (a > b && a > c)
		ft_rotate(stack, "ra");
	else if (b > a && b > c)
		ft_reverse_rotate(stack, "rra");
	else if (a > b)
		ft_swap(*stack, "sa");
	if (a < b && b < c)
		return ;
	ft_sort_three(stack);
}

int		ft_get_max(t_stack *stack_a)
{
	int	tmp;

	tmp = stack_a->val;
	while (stack_a)
	{
		if (stack_a->val > tmp)
			tmp = stack_a->val;
		stack_a = stack_a->next;
	}
	return (tmp);
}

void	ft_sort_two(t_stack **stack)
{
	int	a;
	int	b;

	a = (*stack)->val;
	b = (*stack)->next->val;
	if (a > b)
		ft_rotate(stack, "rb");
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->val != ft_get_max(*stack_a))
		ft_reverse_rotate(stack_a, "rra");
	ft_push(stack_a, stack_b, "pb");
	while ((*stack_a)->val != ft_get_max(*stack_a))
		ft_reverse_rotate(stack_a, "rra");
	ft_push(stack_a, stack_b, "pb");
	ft_sort_three(stack_a);
	ft_sort_two(stack_b);
	ft_push(stack_b, stack_a, "pa");
	ft_push(stack_b, stack_a, "pa");
}
