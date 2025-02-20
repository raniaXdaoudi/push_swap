/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:35:55 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 19:49:55 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_stack	*ft_stack_new(int val)
{
	t_stack	*list1;

	list1 = malloc(sizeof(t_stack));
	if (!list1)
		return (NULL);
	list1->val = val;
	list1->final_pos = -1;
	list1->next = 0;
	return (list1);
}

static t_stack	*ft_return_error(t_stack *stack, char **tab)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(&stack);
	ft_free_tab(tab);
	return (NULL);
}

t_stack	*ft_create_stack(int ac, char **av)
{
	char	**tab;
	t_stack	*stack;
	t_stack	*tmp;
	int		i;
	int		j;

	i = ac;
	stack = NULL;
	while (--i > 0)
	{
		tab = ft_split(av[i], ' ');
		j = ft_tablen(tab);
		while (--j >= 0)
		{
			if (ft_atoi(tab[j]) > MAX_INT || ft_atoi(tab[j]) < MIN_INT)
				return (ft_return_error(stack, tab));
			else
				tmp = ft_stack_new((int)ft_atoi(tab[j]));
			tmp->next = stack;
			stack = tmp;
		}
		ft_free_tab(tab);
	}
	return (stack);
}
