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

/*
	el hijo q juega lol flaco y ve anime
*/
// int	red_flag_pipe(int *fd_pipe, int fd_file1, char *path, char *comand)
int	red_flag_pipe(int *fd_pipe, int fd_file1, char *path, char **comand)
{
	close(fd_pipe[READ_END]);
	dup2(fd_file1, STDIN_FILENO);
	printf("comando 1 %s", comand[0]);
	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);//cerramos el extremo ESCRITURA
	execve(path, comand, NULL);
	perror("execve");

	return (0);
}
/*
	el primer desarrollo de personaje
*/
// int	cigarette_pipe(int *fd_pipe, int fd_file2, char *path, char *comand)
int	cigarette_pipe(int *fd_pipe, int fd_file2, char *path, char **comand)
{
	close(fd_pipe[WRITE_END]);//cerramos el extremo no necesario
	dup2(fd_pipe[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
	printf("comando 2 %s", comand[0]);

	close(fd_pipe[READ_END]);
	dup2(fd_file2, STDOUT_FILENO);

	execve(path, comand, NULL);
	perror("execve");
	
	return (0);
}
