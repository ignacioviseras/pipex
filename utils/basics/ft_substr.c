/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:34:16 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/18 20:34:55 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*substr;
	char			*schar;

	index = 0;
	if (start >= ft_strlen(s) || !*s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	schar = (char *)s;
	while (s[index] || !*s)
	{
		if (index == start)
		{
			ft_strlcpy(substr, schar + index, len + 1);
			return (substr);
		}
		index++;
	}
	return (NULL);
}
