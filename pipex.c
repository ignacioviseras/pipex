/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:20:46 by igvisera          #+#    #+#             */
/*   Updated: 2024/08/03 18:58:50 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	initpipe(t_params *p)
{
	int	fd_pipe[2];
	int	pid;
	int	status;
	int	resultpipe;

	resultpipe = pipe(fd_pipe);
	if (resultpipe == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
		child_pipe(fd_pipe, p->file1, p->comand_path1, p->comand1);
	else
		father_pipe(fd_pipe, p->file2, p->comand_path2, p->comand2);
	wait(&status);
	free_param(p);
	return (0);
}

int	tramited(char *path, char **arguments)
{
	char		**dir;
	t_params	p;

	dir = ft_split(path + 5, ':');
	p.file1 = arguments[1];
	p.file2 = arguments[4];
	p.comand_path1 = load_param(dir, arguments[2]);
	p.comand_path2 = load_param(dir, arguments[3]);
	p.comand1 = split_formated(arguments[2], ' ');
	p.comand2 = split_formated(arguments[3], ' ');
	free_all(dir);
	if ((p.comand_path1 != NULL) && (p.comand_path2 != NULL))
		initpipe(&p);
	else
	{
		free(p.comand_path1);
		free(p.comand_path2);
		free_all(p.comand1);
		free_all(p.comand2);
		exit(1);
	}
	return (0);
}

void	have_env(char **env, char **argv)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp("PATH=", env[x], 5) == 0)
			tramited(env[x] + 5, argv);
		x++;
	}
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		ft_printf("\t--- Error ---\nNeed 5 params\n");
		return (-1);
	}
	else if (env && env[0])
		have_env(env, argv);
	else if (ft_strchr(argv[2], '/') && ft_strchr(argv[3], '/'))
		tramited("", argv);
	else
		ft_printf("\t--- Error ---\nNeed path or absolute route\n");
	return (0);
}
