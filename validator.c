/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:47:55 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/20 13:06:50 by igvisera         ###   ########.fr       */
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
int paramvalidator(int argc, char **argv)
{
	//./pipex infile "ls -l" "wc -l" outfile
	// int x;
	int fd_file1;
	int fd_file2;
	int status;
	char *buffer[BUFFER_SIZE+1];

	if (argc == 1)
	{
		printf("\t--- Error ---\nPasa algun argumento\n");
		return (-1);
	}
	fd_file1 = open(argv[1], O_RDONLY);
	fd_file2 = open(argv[3], O_WRONLY);
	if (fd_file1 == -1 || fd_file2 == -1)
	{
		printf("archivo %s fd->%d\n", argv[1], fd_file1);
		printf("archivo %s fd->%d\n", argv[3], fd_file2);
		printf("\t--- Error ---\nAl abrir el archivo\n");
		return (-1);
	}
	printf("comando a leer %s\n", argv[2]);
	status = read(fd_file1, buffer, BUFFER_SIZE);
	if(status>0)
	{
		buffer[status] = '\0';
		char *puta[] = {"ls","-l", buffer, NULL};
		dup2(fd_file2, STDOUT_FILENO);
		execve("/bin/ls", puta, NULL);
		perror("execve");
	}
	// if (filesvalidator(argv[1], argv[2]) != 0)
	// x = 0;
	// printf("numero de argumentos %i\n", argc);
	// while (x < argc)
	// {
	// 	validate = filesvalidator(argv[x]);
	// 	if (validate == -1)
	// 	{
	// 		printf("\t--- Error ---\nArgumento invalido\n");
	// 		return(-1);
	// 	}
	// 	x++;
	// }
	return(0);
}
