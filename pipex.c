/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:20:46 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/23 21:28:46 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"

/*
	@return
	- 0 its ok.
	@return
	-  -1 error.
*/
int pipe_action(char *file1, char *file2, char *comand1, char *comand2)
{
	//./pipex infile "ls -l" "wc -l" outfile
	int fd_file1;
	int fd_file2;
	int status;
	char buffer[BUFFER_SIZE+1];
	int fd_pipe[2];
	int pid;

	printf("cmd1 %s\n", comand1);
	printf("cmd2 %s\n", comand2);
	if (pipe(fd_pipe) == -1)
    {
        printf("\t--- Error ---\nAl crearse la pipe\n");
        exit(1);
    }
	pid = fork();
	if(pid == 0)//si pid es == 0 significa q es el hijo 1
	{
		close(fd_pipe[READ_END]);
		fd_file1 = open(file1, O_RDONLY);
		if (fd_file1 == -1)//contorl de eerr para abrir el archivo
		{
			printf("\t--- Error ---\nAl abrir el archivo\n");
			printf("archivo %s fd->%d\n", file1, fd_file1);
			return (-1);
		}
		status = read(fd_file1, buffer, BUFFER_SIZE);
		if (status>0)
		{
			buffer[status] = '\0';
			printf("contenido del archivo '%s'\n", buffer);
			char *puta[] = {"ls","-l", buffer, NULL};
			dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
			close(fd_pipe[WRITE_END]);//cerramos el extremo ESCRITURA
			execve("/bin/ls", puta, NULL);
			perror("execve");
		}
	}
	else// el padre
	{
		close(fd_pipe[WRITE_END]);//cerramos el extremo no necesario
		fd_file2 = open(file2, O_WRONLY);
		if (fd_file2 == -1)//contorl de eerr para abrir el archivo
		{
			printf("\t--- Error ---\nAl abrir el archivo\n");
			printf("archivo %s fd->%d\n", file2, fd_file2);
			return (-1);
		}
		dup2(fd_pipe[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
		close(fd_pipe[READ_END]);
		dup2(fd_file2, STDOUT_FILENO);
		//--

        //-------- prueba de split pal comando
	    char **comand_splited;
		comand_splited = ft_split(comand2, ' ');

        
        //-----------------

		char *asd[] = {comand_splited[0], comand_splited[1], NULL};
		dup2(fd_file2, STDOUT_FILENO);
		execve("/usr/bin/grep", asd, NULL);
		free_all(comand_splited);
		perror("execve");
		//--
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
    char **path;
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
            path = ft_split(env[x] + 5, ':');
        	if ((load_param(path, argv[2]) == 0) && (load_param(path, argv[3]) == 0))
            {
                free_all(path);
                pipe_action(argv[1], argv[4], argv[2], argv[3]);
            }
            else
                exit(1);
        }
        x++;
    }
	return (0);
}
