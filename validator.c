/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:47:55 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/21 15:50:15 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"


// int filesvalidator()
// {
// 	return (0);
// }

/*
	@return
	- 0 its ok.
	@return
	-  -1 error.
*/
// int paramvalidator(int argc, char **argv)
// {
// 	//./pipex infile "ls -l" "wc -l" outfile
// 	int fd_file1;
// 	int fd_file2;
// 	int status;
// 	char buffer[BUFFER_SIZE+1];
// 	int fd_pipe[2];
// 	int pid;

// 	if (argc == 1)
// 	{
// 		printf("\t--- Error ---\nPasa algun argumento\n");
// 		return (-1);
// 	}
// 	pipe(fd_pipe);
// 	pid = fork();
// 	if(pid == 0)//si pid es == 0 significa q es el hijo 1
// 	{
// 		close(fd_pipe[READ_END]);
// 		fd_file1 = open(argv[1], O_RDONLY);
// 		if (fd_file1 == -1)//contorl de eerr para abrir el archivo
// 		{
// 			printf("\t--- Error ---\nAl abrir el archivo\n");
// 			printf("archivo %s fd->%d\n", argv[1], fd_file1);
// 			return (-1);
// 		}
// 		status = read(fd_file1, buffer, BUFFER_SIZE);
// 		if (status>0)
// 		{
// 			buffer[status] = '\0';
// 			printf("contenido del archivo '%s'\n", buffer);
// 			char *puta[] = {"ls","-l", buffer, NULL};
// 			dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
// 			close(fd_pipe[WRITE_END]);//cerramos el extremo ESCRITURA
// 			execve("/bin/ls", puta, NULL);
// 			perror("execve");
// 		}
// 	}
// 	else// el padre
// 	{
// 		close(fd_pipe[WRITE_END]);//cerramos el extremo no necesario
// 		fd_file2 = open(argv[3], O_WRONLY);
// 		if (fd_file2 == -1)//contorl de eerr para abrir el archivo
// 		{
// 			printf("\t--- Error ---\nAl abrir el archivo\n");
// 			printf("archivo %s fd->%d\n", argv[3], fd_file2);
// 			return (-1);
// 		}
// 		dup2(fd_pipe[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
// 		close(fd_pipe[READ_END]);
// 		dup2(fd_file2, STDOUT_FILENO);

// 		//--
// 		char *asd[] = {"grep","Makefile", NULL};
// 		dup2(fd_file2, STDOUT_FILENO);
// 		execve("/usr/bin/grep", asd, NULL);
// 		perror("execve");

// 		//--

// 	}
	//---------------------------
	// fd_file1 = open(argv[1], O_RDONLY);
	// fd_file2 = open(argv[3], O_WRONLY);
	// if (fd_file1 == -1 || fd_file2 == -1)
	// {
	// 	printf("archivo %s fd->%d\n", argv[1], fd_file1);
	// 	printf("archivo %s fd->%d\n", argv[3], fd_file2);
	// 	printf("\t--- Error ---\nAl abrir el archivo\n");
	// 	return (-1);
	// }
	// printf("comando a leer %s\n", argv[2]);
	// status = read(fd_file1, buffer, BUFFER_SIZE);
	// printf("statuss-> '%d'\n", status);
	// if (status>0)
	// {
	// 	buffer[status] = '\0';
	// 	printf("contenido del archivo '%s'\n", buffer);
	// 	char *puta[] = {"ls","-l", buffer, NULL};
	// 	dup2(fd_file2, STDOUT_FILENO);
	// 	execve("/bin/ls", puta, NULL);
	// 	perror("execve");
	// }
	
// 	return(0);
// }
