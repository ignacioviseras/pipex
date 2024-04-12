/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:54:30 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/12 20:35:40 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

/*  comunicacion de 3 procesos
	ls -l -> lista contenido
	grep u -> busca la letra "u"
	wc -> muestra la info
		10 91 579
		10 numero de lineas
		91 numero de palabras
		579 numero de bytes
		-l -> numero de lineas nuevas

*/
// int main()
// {
//     int fd1[2];
//     int fd2[2];
//     // int fd3;
//     int status;
//     int pid;

//     //pipe comunicara proceso 1 y proceso 2
//     //                  ls      y   grep
//     pipe(fd1);
//     pid = fork();
//     if (pid == 0) //hijo 1
//     {
//         close(fd1[READ_END]);
//         dup2(fd1[WRITE_END], STDOUT_FILENO);
//         close(fd1[WRITE_END]);
//         execlp("/bin/ls", "ls", "-l", NULL);
//     }
//     else //         super-padre
//     {
//         close(fd1[WRITE_END]);
//         pipe(fd2);//comunica grep con wc (proceso 2 con proceso 3)
//         pid = fork();
//         if (pid == 0) //hijo 2
//         {
//             close(fd2[READ_END]);

//             dup2(fd1[READ_END], STDIN_FILENO);
//             close(fd1[READ_END]);

//             dup2(fd2[WRITE_END], STDOUT_FILENO);
//             close(fd2[WRITE_END]);

//             execlp("/bin/grep", "grep", "u", NULL);
//         }
//         else //padre
//         {
//             close(fd1[READ_END]);
//             close(fd2[WRITE_END]);

//             pid = fork();
//             if (pid == 0)// hijo 3
//             {
//                 dup2(fd2[READ_END], STDIN_FILENO);
//                 close(fd2[READ_END]);
//                 execlp("/usr/bin/wc", "wc", "-l", NULL);

//                 // fd3 = open(FILE_NAME, O_WRONLY );
//                 // dup2(fd2[READ_END], STDIN_FILENO);
//                 // close(fd2[READ_END]);
//                 // dup2(fd3, STDOUT_FILENO);
//                 // execlp("/usr/bin/wc", "wc", "-l", NULL);

//             }
//         }
//     }
//     close(fd2[READ_END]);//cerramos el ultimo que quedaba
//     //usamos wait para esperar a los hijos
//     wait(&status);
//     wait(&status);
//     wait(&status);
//     return(0);
// }

int	main(void)
{
	int fd1[2], fd2[2];
	int status, pid;

	pipe(fd1); /* comunica ls y grep */

	pid = fork();

	if (pid == 0) /* hijo 1*/
	{
		close(fd1[READ_END]); /* cerrar extremo no necesario */

		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);
		execlp("/bin/ls", "ls", "-l", NULL);
	}
	else /* padre */
	{
		close(fd1[WRITE_END]); /* extremo no necesario ya */

		pipe(fd2); /* comunica grep y wc */
		pid = fork();

		if (pid == 0) /* hijo 2 */
		{
			close(fd2[READ_END]); /* cerrar extremo no necesario */

			dup2(fd1[READ_END], STDIN_FILENO);
			close(fd1[READ_END]);

			dup2(fd2[WRITE_END], STDOUT_FILENO);
			close(fd2[WRITE_END]);

			execlp("/bin/grep", "grep", "u", NULL);
		}
		else /* padre */
		{
			close(fd1[READ_END]);  /* cerrar extremo no necesario */
			close(fd2[WRITE_END]); /* cerrar extremo no necesario */
			// pid = fork();

			// if (pid == 0) /* hijo 3*/
			// {
			// 	dup2(fd2[READ_END], STDIN_FILENO);
			// 	close(fd2[READ_END]);

			// 	execlp("/usr/bin/wc", "wc", "-l", NULL);
			// }
		}
	}

	close(fd2[READ_END]); /* cerrar extremo que queda abierto en el padre  */

	/* wait para cada hijo */
	wait(&status);
	wait(&status);
	wait(&status);

	return (0);
}