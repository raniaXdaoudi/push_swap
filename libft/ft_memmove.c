/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:43:11 by radaoudi          #+#    #+#             */
/*   Updated: 2022/09/03 13:35:20 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_cpy;
	const char	*src_cpy;

	if (!dest && !src)
		return (0);
	i = 0;
	dest_cpy = dest;
	src_cpy = src;
	if (dest_cpy > src_cpy)
	{
		while (n-- > 0)
		{
			dest_cpy[n] = src_cpy[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	return (dest);
}
