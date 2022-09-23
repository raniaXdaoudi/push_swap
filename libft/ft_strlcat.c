/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:27:16 by radaoudi          #+#    #+#             */
/*   Updated: 2022/09/03 13:35:59 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = 0;
	if (*src == '\0')
		return (i);
	if (destsize == 0 || destsize < i)
		return (j + destsize);
	else
		j += i;
	while (src[k] && i + k < destsize - 1)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (j);
}
