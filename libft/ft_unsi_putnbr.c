/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:03:22 by radaoudi          #+#    #+#             */
/*   Updated: 2022/09/01 14:59:22 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsi_putnbr(unsigned long long n, char *base)
{
	unsigned long long int	i;
	unsigned long long int	len;

	i = 0;
	len = ft_strlen(base);
	if (check_base(base))
		return (0);
	if (n > len - 1)
	{
		i += ft_unsi_putnbr(n / len, base);
	}
	i += ft_putchar_fd(base[n % len], 1);
	return (i);
}
