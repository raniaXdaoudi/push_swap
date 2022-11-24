/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:35:55 by rania             #+#    #+#             */
/*   Updated: 2022/11/24 13:45:08 by rania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_stack	*ft_stack_new(int val, int pos)
{
	t_stack	*list1;

	list1 = malloc(sizeof(t_stack));
	if (!list1)
		return (NULL);
	list1->val = val;
	list1->pos = pos;
	list1->final_pos = -1;
	list1->next = 0;
	return (list1);
}

t_stack	*ft_create_stack(int ac, char **av)
{
	char	**tab;
	t_stack	*stack;
	t_stack	*tmp;
	int		i;
	int		j;
	int		pos;

	i = ac - 1;
	stack = NULL;
	while (i > 0)
	{
		tab = ft_split(av[i], ' ');
		j = ft_tablen(tab) - 1;
		pos = i + j;
		while (j >= 0)
		{
			if (ft_atoi(tab[j]) > MAX_INT || ft_atoi(tab[j]) < MIN_INT)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(&stack);
				return (NULL);
			}
			else
				tmp = ft_stack_new((int)ft_atoi(tab[j]), pos--);
			tmp->next = stack;
			stack = tmp;
			j--;
		}
		i--;
		ft_free_tab(tab);
	}
	return (stack);
}
