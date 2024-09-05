/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandour <amandour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:25:02 by amandour          #+#    #+#             */
/*   Updated: 2024/01/13 12:25:34 by amandour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	int	b;

	b = 0;
	if (n < 16)
	{
		if (c == 'x')
			b += write(1, &"0123456789abcdef"[n], 1);
		else if (c == 'X')
			b += write(1, &"0123456789ABCDEF"[n], 1);
	}
	else
	{
		b += ft_puthexa(n / 16, c);
		b += ft_puthexa(n % 16, c);
	}
	return (b);
}
