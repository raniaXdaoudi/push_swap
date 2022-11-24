/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:28:19 by rania             #+#    #+#             */
/*   Updated: 2022/11/24 13:55:29 by rania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_arr(t_stack **stack, int copy[])
{
	int		i;
	t_stack	*get_val;

	i = 0;
	get_val = *stack;
	while (get_val)
	{
		copy[i] = get_val->val;
		get_val = get_val->next;
		i++;
	}
}

void	set_final_pos(t_stack **stack)
{
	int		i;
	int		pos;
	int		copy[ft_stack_size(*stack)];
	int		copylen;
	t_stack	*tmp;

	copy_arr(stack, copy);
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
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	num;
	int	max_num;
	int max_bits;

	size = ft_stack_size(*stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0) ++max_bits;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->final_pos;
			if (((num >> i) & 1) == 1)	ft_rotate(stack_a, "ra");
			else	ft_push(stack_a, stack_b, "pb");
		}
		while (ft_stack_size(*stack_b) > 0)	ft_push(stack_b, stack_a, "pa");
	}
}
