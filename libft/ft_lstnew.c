/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:17:42 by radaoudi          #+#    #+#             */
/*   Updated: 2022/09/03 13:35:04 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list1;

	list1 = malloc(sizeof(t_list));
	if (!list1)
		return (NULL);
	list1->content = content;
	list1->next = 0;
	return (list1);
}
