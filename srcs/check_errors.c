/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:41:07 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 18:47:00 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char **av)
{
	int	i;
	int	j;
	int	new_nb;

	i = 0;
	while (av[++i])
	{
		j = -1;
		new_nb = 1;
		while (av[i][++j])
		{
			if ((av[i][j] == '-' && (!ft_isdigit(av[i][j + 1]) || new_nb == 0))
			|| (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-'))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			if (av[i][j] == ' ')
				new_nb = 1;
			else
				new_nb = 0;
		}
	}
	return (1);
}

int	ft_check_double(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->val == tmp2->val)
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(stack);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
