/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:28:19 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 19:33:53 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_arr(t_stack **stack)
{
	int		i;
	int		*copy;
	t_stack	*get_val;

	i = 0;
	get_val = *stack;
	copy = malloc(sizeof(int) * ft_stack_size(*stack));
	if (!copy)
		return (NULL);
	while (get_val)
	{
		copy[i] = get_val->val;
		get_val = get_val->next;
		i++;
	}
	return (copy);
}

void	set_final_pos(t_stack **stack)
{
	int		i;
	int		pos;
	int		*copy;
	int		copylen;
	t_stack	*tmp;

	copy = copy_arr(stack);
	copylen = ft_stack_size(*stack);
	tmp = *stack;
	while (tmp)
	{
		i = 0;
		pos = ft_stack_size(*stack) - 1;
		while (i < copylen)
		{
			if (copy[i] > tmp->val)
				pos--;
			i++;
		}
		tmp->final_pos = pos;
		tmp = tmp->next;
	}
	free(copy);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	num;
	int	max_bits;

	size = ft_stack_size(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->final_pos;
			if (((num >> i) & 1) == 1)
				ft_rotate(stack_a, "ra");
			else
				ft_push(stack_a, stack_b, "pb");
		}
		while (ft_stack_size(*stack_b) > 0)
			ft_push(stack_b, stack_a, "pa");
	}
}
