/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rania <rania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:19:28 by rania             #+#    #+#             */
/*   Updated: 2022/09/23 18:42:39 by rania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_stack
{
	int				val;
	int				pos;
	struct s_stack	*next;
}	t_stack;

int ft_create_stack(int ac, char **av);
int	ft_check_arg(char **av);

#endif
