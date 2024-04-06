/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printText.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:46:26 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/17 14:48:35 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	ft_print_char(int s)
{
	return (write(1, &s, 1));
}

int	ft_print_string(char *s)
{
	if (!s)
		return (write(1, "(null)", ft_strlen("(null)")));
	return (write(1, s, ft_strlen(s)));
}

int	ft_print_percent(void)
{
	return (write(1, "%%", 1));
}
