/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:17:24 by rania             #+#    #+#             */
/*   Updated: 2022/10/03 16:00:27 by rania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_display(t_stack *lst)
{
	while (lst)
	{
		printf("val = %i; pos = %i\n", lst->val, lst->pos);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_check_arg(av) || ac <= 1)
		return (0);
	stack_a = ft_create_stack(ac, av);
	stack_b = NULL;
	ft_sort_five(&stack_a, &stack_b);
	// ft_printf("STACK A:\n");
	// ft_stack_display(stack_a);
	// ft_printf("STACK B:\n");
	// ft_stack_display(stack_b);

	free_stack(&stack_a);
	free_stack(&stack_b);
	return 0;
}
