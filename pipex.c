/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:20:46 by igvisera          #+#    #+#             */
/*   Updated: 2024/07/28 19:05:20 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	initpipe(t_params *p)
{
	int	fd_files[2];
	int	fd_pipe[2];
	int	pid;
	int	status;
	int	resultpipe;

	fd_files[0] = open(p->file1, O_CREAT | O_RDONLY | O_TRUNC, 0777);
	fd_files[1] = open(p->file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_files[0] < 0 || fd_files[1] < 0)
	{
		ft_printf("\t--- Error ---\nWhen opening the file\n");
		exit(1);
	}
	resultpipe = pipe(fd_pipe);
	if (resultpipe == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
		red_flag_pipe(fd_pipe, fd_files[0], p->comand_path1, p->comand1);
	else
		cigarette_pipe(fd_pipe, fd_files[1], p->comand_path2, p->comand2);
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
