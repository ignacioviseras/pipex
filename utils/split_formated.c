/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:49:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/29 19:50:12 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./utils.h"

static int	n_words(char const *s, char c)
{
	int	words;
	int	index;

	index = 0;
	words = 0;
	index = 0;
	if (!s)
		return (0);
	while (s[index] && s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			while (s[index] && s[index] == c)
				index++;
			words++;
		}
		else
			index++;
	}
	if (s[index - 1] && s[index - 1] != c)
		words++;
	return (words);
}

char	**split_formated(char const *s, char c)
{
	size_t	i;
	size_t	len_word;
	char	**str;

	i = 0;
	str = ft_calloc(n_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s && *s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break;
		if (!ft_strchr(s, c))
			len_word = ft_strlen(s);
		else
			len_word = ft_strchr(s, c) - s;
		str[i] = ft_substr(s, 0, len_word);
		if (!str[i++])
			return (free_all(str), NULL);
		s += len_word;
	}
	str[i] = NULL; // Añadir NULL al final de la matriz
	return (str);
}

