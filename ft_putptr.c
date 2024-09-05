/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandour <amandour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:53:10 by amandour          #+#    #+#             */
/*   Updated: 2024/01/11 16:08:05 by amandour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	i;

	i = 0;
	if (ptr < 16)
	{
		i = write(1, &"0123456789abcdef"[ptr], 1);
		if (i < 0)
			return (-1);
	}
	else
	{
		i += ft_putptr(ptr / 16);
		i += ft_putptr(ptr % 16);
	}
	return (i);
}
