/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:47:55 by igvisera          #+#    #+#             */
/*   Updated: 2024/08/02 18:49:02 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	*access_absolute(char *path)
{
	int		fd_dir1;
	char	*comand_ok;

	fd_dir1 = access(path, X_OK);
	if (fd_dir1 == -1)
	{
		ft_printf("\t--- Error ---\nThere is no access\n");
		return (NULL);
	}
	comand_ok = ft_strdup(path);
	return (comand_ok);
}

char	*access_validate(char **path, char *comand)
{
	char	*dir1;
	int		fd_dir1;
	int		x;

	x = 0;
	fd_dir1 = -1;
	while (path[x] || fd_dir1 == 0)
	{
		dir1 = ft_strjoin(path[x], comand);
		fd_dir1 = access(dir1, X_OK);
		if (fd_dir1 == 0)
			return (dir1);
		free(dir1);
		x++;
	}
	if (fd_dir1 == -1)
	{
		ft_printf("\t--- Error ---\nThere is no access to any directory\n");
		return (NULL);
	}
	return (NULL);
}

char	*load_param(char **path, char *comand)
{
	char	**comand_splited;
	char	*result;

	if (ft_strchr(comand, '/'))
	{
		if (ft_strchr(comand, ' '))
		{
			comand_splited = ft_split(comand, ' ');
			result = access_absolute(comand_splited[0]);
			free_all(comand_splited);
		}
		else
			result = access_absolute(comand);
	}
	else if (ft_strchr(comand, ' '))
	{
		comand_splited = ft_split(comand, ' ');
		result = access_validate(path, comand_splited[0]);
		free_all(comand_splited);
	}
	else
		result = access_validate(path, comand);
	return (result);
}

void	control_file(int fd)
{
	if (fd < 0)
	{
		ft_printf("\t--- Error ---\nWhen opening the file\n");
		exit(1);
	}
}
