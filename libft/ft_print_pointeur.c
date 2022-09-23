/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:11:10 by radaoudi          #+#    #+#             */
/*   Updated: 2022/09/01 14:59:22 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointeur(va_list tab)
{
	int		count;
	void	*p;

	p = 0;
	count = 0;
	p = va_arg(tab, void *);
	write(1, "0x", 2);
	count += ft_unsi_putnbr((unsigned long long)p, "0123456789abcdef");
	return (count + 2);
}
