/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandour <amandour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:18:08 by amandour          #+#    #+#             */
/*   Updated: 2024/01/14 11:08:32 by amandour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr2(long n, int b)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		b = ft_putnbr2(n / 10, b);
		ft_putnbr2(n % 10, b);
	}
	return (b + 1);
}

int	ft_putnbr(int n)
{
	int		b;
	long	nb;

	b = 0;
	nb = n;
	if (nb < 0)
	{
		b += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 0)
		b += ft_putnbr2(nb, b);
	if (n < 0)
		b--;
	return (b);
}
