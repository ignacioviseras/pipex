/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:51:57 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/05 20:58:02 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_pipe(int *fd_pipe, char *file1, char *path, char **comand)
{
	int fd_file1;

	fd_file1 = open(file1, O_RDONLY);
	if (fd_file1 < 0)
	{
		perror("open");
		return (0);
	}
	close(fd_pipe[READ_END]);
	dup2(fd_file1, STDIN_FILENO);
	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);
	execve(path, comand, NULL);
	perror("execve");
	return (0);
}


int	father_pipe(int *fd_pipe, char *file2, char *path, char **comand)
{
	int fd_file2;

	fd_file2 =	open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_file2 < 0)
		perror("open");
	close(fd_pipe[WRITE_END]);
	dup2(fd_pipe[READ_END], STDIN_FILENO);
	close(fd_pipe[READ_END]);
	dup2(fd_file2, STDOUT_FILENO);
	execve(path, comand, NULL);
	perror("execve");
	return (0);
}
