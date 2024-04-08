/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:44:01 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:22:07 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	ft_elemts(char const *str, va_list args)
{
	int	content;

	content = 0;
	if (*(str + 1) == 'c')
		content += ft_print_char(va_arg(args, int));
	if (*(str + 1) == 's')
		content += ft_print_string(va_arg(args, char *));
	if (*(str + 1) == 'p')
		content += ft_print_pointer(va_arg(args, unsigned long long));
	if (*(str + 1) == 'd' || *(str + 1) == 'i')
		content += ft_print_int(va_arg(args, int));
	if (*(str + 1) == 'u')
		content += ft_print_unsigned(va_arg(args, unsigned int));
	if (*(str + 1) == 'x')
		content += ft_print_hex(va_arg(args, unsigned int), HEXLOWER);
	if (*(str + 1) == 'X')
		content += ft_print_hex(va_arg(args, unsigned int), HEXUPPER);
	if (*(str + 1) == '%')
		content += ft_print_percent();
	return (content);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		content;

	content = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			content += ft_elemts(str, args);
			str++;
		}
		else
		{
			write(1, str, 1);
			content++;
		}
		str++;
	}
	va_end(args);
	return (content);
}
