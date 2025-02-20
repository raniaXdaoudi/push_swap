/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:19:28 by rania             #+#    #+#             */
/*   Updated: 2022/11/25 19:31:08 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include "libft.h"

typedef struct s_stack
{
	int				val;
	int				final_pos;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_create_stack(int ac, char **av);
t_stack	*ft_stack_new(int val);
t_stack	*ft_stack_last(t_stack *lst);
int		ft_check_maxint(t_stack **stack);
int		ft_check_double(t_stack **stack);
int		ft_check_arg(char **av);
int		ft_stack_size(t_stack *stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	set_final_pos(t_stack **stack);
void	free_stack(t_stack **stack);
void	ft_stack_add_back(t_stack **alst, t_stack *new);
void	ft_stack_add_front(t_stack **alst, t_stack *new);
void	ft_swap(t_stack *stack, char const *move);
void	ft_push(t_stack **stack_src, t_stack **stack_dest, char *move);
void	ft_rotate(t_stack **stack, char *move);
void	ft_reverse_rotate(t_stack **stack, char *move);
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_two(t_stack **stack, char *move);

#endif
