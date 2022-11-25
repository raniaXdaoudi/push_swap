/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:17:24 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 20:01:42 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_is_sorted(t_stack **stack_a)
{
	int		prev_val;
	t_stack	*tmp;

	tmp = *stack_a;
	prev_val = tmp->val;
	while (tmp)
	{
		if (prev_val > tmp->val)
			return (0);
		prev_val = tmp->val;
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_checker(t_stack *stack_a)
{
	if (check_is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	if (!ft_check_double(&stack_a))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_check_arg(av) || ac <= 1)
		return (0);
	stack_a = ft_create_stack(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	if (!ft_checker(stack_a))
		return (0);
	if (ft_stack_size(stack_a) == 2)
		ft_sort_two(&stack_a, "ra");
	else if (ft_stack_size(stack_a) == 3)
		ft_sort_three(&stack_a);
	else if (ft_stack_size(stack_a) == 5)
		ft_sort_five(&stack_a, &stack_b);
	else
	{
		set_final_pos(&stack_a);
		radix_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
