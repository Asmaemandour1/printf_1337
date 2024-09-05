/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandour <amandour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:22:16 by amandour          #+#    #+#             */
/*   Updated: 2024/01/13 12:15:32 by amandour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
	{
		i += ft_putchar(n + 48);
	}
	else
	{
		i += ft_putunsigned(n / 10);
		i += ft_putunsigned(n % 10);
	}
	return (i);
}
