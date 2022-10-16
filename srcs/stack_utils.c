/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:58:45 by rania             #+#    #+#             */
/*   Updated: 2022/10/03 14:16:47 by rania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*ft_stack_last(t_stack *lst)
{
	while (lst && (lst->next != NULL))
		lst = lst->next;
	return (lst);
}

void	ft_stack_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*tmp;

	if (alst && *alst)
	{
		tmp = ft_stack_last(*alst);
		tmp->next = new;
	}
	else
		*alst = new;
}

void	ft_stack_add_front(t_stack **alst, t_stack *new)
{
	if (alst && *alst)
		new->next = *alst;
	*alst = new;
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
