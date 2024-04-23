/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:47:55 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/23 21:22:51 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"

int access_validate(char **path, char *comand)
{
    char *dir1;
    int fd_dir1;
    int x;

	x = 0;
	fd_dir1 = -1;
	while (path[x] || fd_dir1 == 0)
	{
		dir1 = ft_strjoin(path[x], comand);
		fd_dir1 = access(dir1, X_OK);
		if (fd_dir1 == 0)
		{
			printf("Tienes acceso\n");
			free(dir1);
			break;
		}
		free(dir1);
		x++;
	}
	printf("estado de acceso '%d'\n", fd_dir1);
	if (fd_dir1 == -1)
	{
		printf("No hay accesso a ninugn directorio\n");
		return (-1);
	}
	return(0);
}

int	load_param(char **path, char *comand)
{
	char **comand_splited;
	int	access;

	if (ft_strchr(comand, ' '))
	{
		comand_splited = ft_split(comand, ' ');
		access = access_validate(path, comand_splited[0]);
		free_all(comand_splited);
	}
	else
		access = access_validate(path, comand);
	return (access);
}

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