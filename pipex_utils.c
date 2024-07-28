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

int	red_flag_pipe(int *fd_pipe, int fd_file1, char *path, char **comand)
{
	close(fd_pipe[READ_END]);
	dup2(fd_file1, STDIN_FILENO);
	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);
	execve(path, comand, NULL);
	perror("execve");
	return (0);
}

int	cigarette_pipe(int *fd_pipe, int fd_file2, char *path, char **comand)
{
	close(fd_pipe[WRITE_END]);
	dup2(fd_pipe[READ_END], STDIN_FILENO);
	close(fd_pipe[READ_END]);
	dup2(fd_file2, STDOUT_FILENO);
	execve(path, comand, NULL);
	perror("execve");
	return (0);
}
