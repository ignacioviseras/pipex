/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:35:16 by igvisera          #+#    #+#             */
/*   Updated: 2024/07/28 16:42:37 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	if (!s || !*s)
		return (NULL);
	len = ft_strlen((char *)s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s, len + 1);
	return (ptr);
}
