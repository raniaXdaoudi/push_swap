/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radaoudi <radaoudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:12:38 by radaoudi          #+#    #+#             */
/*   Updated: 2022/09/01 14:59:22 by radaoudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	tab;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(tab, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_find_conv((char *)str, tab, ++i);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(tab);
	return (count);
}

int	ft_find_conv(char *str, va_list tab, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_char(tab);
	else if (str[i] == 's')
		count += ft_print_string(tab);
	else if (str[i] == 'p')
		count += ft_print_pointeur(tab);
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_decimal(tab);
	else if (str[i] == 'u')
		count += ft_print_unsi(tab);
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_print_hexa(tab, str[i]);
	else if (str[i] == '%')
		count += write(1, "%", 1);
	return (count);
}
