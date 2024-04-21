/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:37:47 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/21 17:37:59 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*mem;
	size_t	index;

	mem = (char *)s;
	index = 0;
	while (index != n)
	{
		mem[index] = c;
		index++;
	}
	return (s);
}
