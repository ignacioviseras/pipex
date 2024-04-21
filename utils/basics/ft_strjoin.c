/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:56:38 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/21 19:25:35 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../utils.h"

static size_t	ft_newstrlcpy(char *dst, char *src, size_t size)
{
	size_t	index;
	size_t	src_lenght;

	index = 0;
	src_lenght = ft_strlen(src);
	if (size == 0)
		return (src_lenght);
	while (src[index] != '\0' && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '/';
	dst[index+1] = '\0';
	return (src_lenght+1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*c1;
	size_t	len_max;

	len_max = (ft_strlen(s1) + ft_strlen(s2)) + 2;
	if (!s1 || !s2)
		return (NULL);
	c1 = (char *)ft_calloc(len_max, sizeof(char));
	if (!c1)
		return (NULL);
	ft_newstrlcpy(c1, (char *)s1, ft_strlen((const char *)s1) + 1);
	ft_strlcat(c1, s2, len_max);
	return (c1);
}
