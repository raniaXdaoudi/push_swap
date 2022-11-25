/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:55 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 19:30:11 by radaoudi         ###   ########.fr       */
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

static int	ft_get_min(t_stack *stack_a)
{
	int	tmp;

	tmp = stack_a->val;
	while (stack_a)
	{
		if (stack_a->val < tmp)
			tmp = stack_a->val;
		stack_a = stack_a->next;
	}
	return (tmp);
}

void	ft_sort_two(t_stack **stack, char *move)
{
	int	a;
	int	b;

	a = (*stack)->val;
	b = (*stack)->next->val;
	if (a > b)
		ft_rotate(stack, move);
}

int	check_reverse_sorted(t_stack **stack_a)
{
	int		ret;
	int		prev_val;
	t_stack	*tmp;

	ret = 1;
	tmp = *stack_a;
	prev_val = tmp->val + 1;
	while (tmp)
	{
		if (prev_val < tmp->val)
			ret = 0;
		prev_val = tmp->val;
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_last(*stack_a)->val == ft_get_min(*stack_a))
		ft_reverse_rotate(stack_a, "rra");
	while ((*stack_a)->val != ft_get_min(*stack_a))
		ft_rotate(stack_a, "ra");
	ft_push(stack_a, stack_b, "pb");
	if (ft_stack_last(*stack_a)->val == ft_get_min(*stack_a))
		ft_reverse_rotate(stack_a, "rra");
	while ((*stack_a)->val != ft_get_min(*stack_a))
		ft_rotate(stack_a, "ra");
	ft_push(stack_a, stack_b, "pb");
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, "pa");
	ft_push(stack_b, stack_a, "pa");
}
