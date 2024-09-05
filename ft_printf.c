/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandour <amandour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:43:57 by amandour          #+#    #+#             */
/*   Updated: 2024/01/14 11:08:15 by amandour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char sp, va_list ap)
{
	int	n;

	n = 0;
	if (sp == 'c')
		n += ft_putchar(va_arg(ap, int));
	else if (sp == 'd' || sp == 'i')
		n += ft_putnbr(va_arg(ap, int));
	else if (sp == 's')
		n += ft_putstr(va_arg(ap, char *));
	else if (sp == 'x')
		n += ft_puthexa(va_arg(ap, unsigned int), 'x');
	else if (sp == 'X')
		n += ft_puthexa(va_arg(ap, unsigned int), 'X');
	else if (sp == 'u')
		n += ft_putunsigned(va_arg(ap, unsigned int));
	else if (sp == 'p')
	{
		n += write(1, "0x", 2);
		n += ft_putptr(va_arg(ap, unsigned long));
	}
	else
		n += write(1, &sp, 1);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;
	int		i;

	va_start(arg, format);
	i = 0;
	count = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			count += ft_format(format[i + 1], arg);
			i++;
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
