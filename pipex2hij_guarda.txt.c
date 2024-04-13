/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:50:47 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/06 16:09:33 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int main()
{
	int fd1[2];
	int fd2;
	int status;
	int pid;
	pipe(fd1);
	pid = fork();
	if(pid == 0)//si pid es == 0 significa q es el hijo 1
	{
		//el hijo 1 ejecuta el primer comando (ls -l)
		close(fd1[READ_END]);//cerramos el extremo no necesario
		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);//cerramos el extremo ESCRITURA
		execlp("/bin/ls", "ls", "-l", NULL);
	}
	else// padre que genera un hijo
	{
		close(fd1[WRITE_END]);//cerramos el extremo no necesario
		pid = fork();//creacion del hijo
		if (pid == 0)
		{
			fd2 = open(FILE_NAME, O_WRONLY);//abrimos el archivo .txt
			dup2(fd1[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
			close(fd1[READ_END]);//lo cerramos pq no se utilizara mas

			dup2(fd2, STDOUT_FILENO);//redirecccionamos la respuesta del comando al archivo .txt
			execlp("/usr/bin/wc", "grep", "u", NULL);//mismo funcionamientoo q el execlp de arriba
			ft_printf("Accede???\n");
		}
		else //SUPER-PADRE
		{
			close(fd1[READ_END]);//cerramos el extremo de lectura
		}
	}
	/*  Para esperar a los hijos */
	wait(&status);
	wait(&status);
	return(0);
}
