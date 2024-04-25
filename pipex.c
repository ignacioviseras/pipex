/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:20:46 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/25 23:08:18 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"

/*
	@return
	- 0 its ok.
	@return
	-  -1 error.
*/
// int pipe_action(char *file1, char *file2, char *comand1, char *comand2)
// {
// 	//./pipex infile "ls -l" "wc -l" outfile
// 	int fd_file1;
// 	int fd_file2;
// 	int status;
// 	char buffer[BUFFER_SIZE+1];
// 	int fd_pipe[2];
// 	int pid;

// 	printf("cmd1 %s\n", comand1);
// 	printf("cmd2 %s\n", comand2);
// 	if (pipe(fd_pipe) == -1)
//     {
//         printf("\t--- Error ---\nAl crearse la pipe\n");
//         exit(1);
//     }
// 	pid = fork();
// 	if(pid == 0)//si pid es == 0 significa q es el hijo 1
// 	{
// 		close(fd_pipe[READ_END]);
// 		fd_file1 = open(file1, O_RDONLY);
// 		if (fd_file1 == -1)//contorl de eerr para abrir el archivo
// 		{
// 			printf("\t--- Error ---\nAl abrir el archivo\n");
// 			printf("archivo %s fd->%d\n", file1, fd_file1);
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
// 		fd_file2 = open(file2, O_WRONLY);
// 		if (fd_file2 == -1)//contorl de eerr para abrir el archivo
// 		{
// 			printf("\t--- Error ---\nAl abrir el archivo\n");
// 			printf("archivo %s fd->%d\n", file2, fd_file2);
// 			return (-1);
// 		}
// 		dup2(fd_pipe[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
// 		close(fd_pipe[READ_END]);
// 		dup2(fd_file2, STDOUT_FILENO);
// 		//--

//         //-------- prueba de split pal comando
// 	    char **comand_splited;
// 		comand_splited = ft_split(comand2, ' ');

//         //-----------------

// 		char *asd[] = {comand_splited[0], comand_splited[1], NULL};
// 		dup2(fd_file2, STDOUT_FILENO);
// 		execve("/usr/bin/grep", asd, NULL);
// 		free_all(comand_splited);
// 		perror("execve");
// 		//--
// 	}
// 	return (0);
// }

/*
	el hijo q juega lol flaco y ve anime
*/
int	red_flag_pipe(int *fd_pipe, int fd_file1, char *path, char **comand)
{
	close(fd_pipe[READ_END]);
	dup2(fd_file1, STDIN_FILENO);

	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);//cerramos el extremo ESCRITURA

	execve(path, comand, NULL);
	perror("execve");

	return (0);
}
/*
	el primer desarrollo de personaje
*/
int	cigarette_pipe(int *fd_pipe, int fd_file2, char *path, char **comand)
{
	close(fd_pipe[WRITE_END]);//cerramos el extremo no necesario
	dup2(fd_pipe[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
	
	close(fd_pipe[READ_END]);
	dup2(fd_file2, STDOUT_FILENO);
 
	execve(path, comand, NULL);
	perror("execve");
	
	return (0);
}

// int	initpipe(char *path1, char *path2, char **comand1, char **comand2)
int	initpipe(char *path1, char *path2, char **initials)
{
	int fd_files[2];
	int fd_pipe[2];
	int pid;
	/*
		O_CREAT: Indica que se debe crear el archivo si no existe.
		O_WRONLY: Indica que el archivo se abrirá solo para escritura.
		O_TRUNC: Indica que si el archivo ya existe, se trunca (es decir, se borra su contenido).
		0644 son los permisos del archivo. Estos permisos especifican que el propietario tiene 
			permiso de lectura y escritura, mientras que el grupo y otros solo tienen permiso de lectura.
			Los permisos se especifican en octal.
	*/
	printf("arch1 %s\n", path1);
	printf("arch1 %s\n", path2);

	fd_files[0] = open(path1, O_CREAT | O_RDONLY | O_TRUNC, 0777);
	fd_files[1] = open(path2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	printf("arch1 %d\n", fd_files[0]);
	printf("arch2 %d\n", fd_files[1]);
	if (fd_files[0] < 0 || fd_files[1] < 0)
	{
		printf("\t--- Error ---\nAl abrir el archivo\n");
        exit(1);
	}
	pid = fork();
	if (pid == 0)// hijo
		red_flag_pipe(fd_pipe, fd_files[0], path1, initials[1][0]);
	else //padre
		cigarette_pipe(fd_pipe, fd_files[1], path2, initials[1][1]);
	free_all(initials[1][0]);
	free_all(initials[1][1]);
	
	return (0);
}

int	tramited(char *path, char **arguments)
{
	char **dir;
	// char *path1;
	// char *path2;
	// char **comand1;
	// char **comand2;
	char **initials;

	dir = ft_split(path + 5, ':');
	initials[0][0] =load_param(dir, arguments[2]);
	initials[0][1] =load_param(dir, arguments[3]);
	// path1 = load_param(dir, arguments[2]);
	// path2 = load_param(dir, arguments[3]);
	free_all(dir);
	// comand1 = ft_split(arguments[2], ' ');
	// comand2 = ft_split(arguments[3], ' ');
	initials[1][0] = ft_split(arguments[2], ' ');
	initials[1][1] = ft_split(arguments[3], ' ');
	if ((initials[0][0] != NULL) && (initials[0][1] != NULL))
	// if ((path1 != NULL) && (path2 != NULL))
	{
		initpipe(arguments[1], arguments[4], initials);
		// initpipe(path1, path2, comand1, comand2);
		free(initials[0][0]);
		free(initials[0][1]);
	}
	else
	{
		exit(1);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
    int x;

    x = 0;
    if (argc != 5)
	{
		printf("\t--- Error ---\nNecesitas 5 parametros\n");
		return (-1);
	}
    while (env[x])
    {
        if (ft_strncmp("PATH=", env[x], 5) == 0)
        {
            tramited(env[x] + 5, argv);
        }
        x++;
    }
	return (0);
}





// int pipe_action(char *file1, char *file2, char *comand1, char *comand2)
// {
// 	//./pipex infile "ls -l" "wc -l" outfile
// 	int fd_file1;
// 	int fd_file2;
// 	int status;
// 	char buffer[BUFFER_SIZE+1];
// 	int fd_pipe[2];
// 	int pid;

// 	printf("cmd1 %s\n", comand1);
// 	printf("cmd2 %s\n", comand2);
// 	if (pipe(fd_pipe) == -1)
//     {
//         printf("\t--- Error ---\nAl crearse la pipe\n");
//         exit(1);
//     }
// 	pid = fork();
// 	if(pid == 0)//si pid es == 0 significa q es el hijo 1
// 	{
// 		close(fd_pipe[READ_END]);
// 		fd_file1 = open(file1, O_RDONLY);
// 		if (fd_file1 == -1)//contorl de eerr para abrir el archivo
// 		{
// 			printf("\t--- Error ---\nAl abrir el archivo\n");
// 			printf("archivo %s fd->%d\n", file1, fd_file1);
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
// 		fd_file2 = open(file2, O_WRONLY);
// 		if (fd_file2 == -1)//contorl de eerr para abrir el archivo
// 		{
// 			printf("\t--- Error ---\nAl abrir el archivo\n");
// 			printf("archivo %s fd->%d\n", file2, fd_file2);
// 			return (-1);
// 		}
// 		dup2(fd_pipe[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
// 		close(fd_pipe[READ_END]);
// 		dup2(fd_file2, STDOUT_FILENO);
// 		//--

//         //-------- prueba de split pal comando
// 	    char **comand_splited;
// 		comand_splited = ft_split(comand2, ' ');

//         //-----------------

// 		char *asd[] = {comand_splited[0], comand_splited[1], NULL};
// 		dup2(fd_file2, STDOUT_FILENO);
// 		execve("/usr/bin/grep", asd, NULL);
// 		free_all(comand_splited);
// 		perror("execve");
// 		//--
// 	}
// 	return (0);
// }





























// int main(int argc, char **argv, char **env)
// {
//     char **path;
//     int x;

//     x = 0;
//     if (argc != 5)
// 	{
// 		printf("\t--- Error ---\nNecesitas 5 parametros\n");
// 		return (-1);
// 	}
//     while (env[x])
//     {
//         if (ft_strncmp("PATH=", env[x], 5) == 0)
//         {
//             path = ft_split(env[x] + 5, ':');
//         	if ((load_param(path, argv[2]) == 0) && (load_param(path, argv[3]) == 0))
//             {
//                 free_all(path);
//                 pipe_action(argv[1], argv[4], argv[2], argv[3]);
//             }
//             else
//                 exit(1);
//         }
//         x++;
//     }
// 	return (0);
// }
