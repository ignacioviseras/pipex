/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printNumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:47:20 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/17 14:47:47 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	ft_print_int(int n)
{
	int	count;
	int	aux;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", sizeof("-2147483648") - 1));
	else if (n < 0)
	{
		n = n * -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
	{
		count += ft_print_int((n / 10));
		aux = (n % 10) + '0';
		count += write(1, &aux, 1);
	}
	else
	{
		aux = n + '0';
		count += write(1, &aux, 1);
	}
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;
	int	aux;

	count = 0;
	if (n > 9)
	{
		count += ft_print_unsigned((n / 10));
		aux = (n % 10) + '0';
		count += write(1, &aux, 1);
	}
	else
	{
		aux = n + '0';
		count += write(1, &aux, 1);
	}
	return (count);
}

int	ft_print_hex(unsigned long long n, char *baseFormat)
{
	int	count;
	int	aux;

	count = 0;
	if (n > 15)
	{
		count += ft_print_hex((n / 16), baseFormat);
		aux = baseFormat[(n % 16)];
		count += write(1, &aux, 1);
	}
	else
	{
		aux = baseFormat[(n % 16)];
		count += write(1, &aux, 1);
	}
	return (count);
}

int	ft_print_pointer(unsigned long long n)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_print_hex(n, HEXLOWER);
	return (count);
}
