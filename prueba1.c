/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:50:47 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/13 18:57:09 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

// int	main(void)
// {
// 	//fd 0 es el de lectura
// 	//fd 1 es el de escritura
// 	int fd[2];
// 	pid_t pidC;
// 	int num;     //n de byte leidos
// 	char bf[10];
// 		//aqui es dnd se almacena el mensaje (le estoy fozando 10 caracteres ahora mismo)

// 	if (pipe(fd) == -1) //need to add control errors
// 		return (0);
// 	pidC = fork();
// 	if (pidC == 0) // hijo
// 	{
// 		close(fd[0]); //cerramos el fd de leer
// 		write(fd[1], "acede al hijo\n", 15);
// 		close(fd[1]); //cerramos el fd de escritura
// 		exit(0);
// 	}
// 	else if (pidC == -1) //error
// 		return (0);
// 	else // padre
// 	{
// 		close(fd[1]); //cerramos el fd de escritura
// 		num = read(fd[0], bf, sizeof(bf));
// 		printf("Numero de bytes leidos por el padre '%d'\n", num);
// 		close(fd[0]); //cerramos el fd de leer
// 		return (0);
// 	}
// }


//llamadas al sistema y comunicacion de 2 procesos
//ls -l lista info de archivos
//wc muestra el numero de lineas palabras y byte
// > redirecciona la salida stdout al .txt q se indica

//programa padre crea 2 hijos
//hijo 1 ejecuta ls -l
//hijo 2 ejecuta wc y guardara el resultado en un .txt
/*	
logica de funcionamiento 
cuando ejecutamos ls -l saca el resultado por stdout (standar output [la terminal])
si usamos dup2 podemos redireccionar la entrada de stdin y stdout
*/

// int main()
// {
// 	/* fd1
// 		arrays de files descriptors 
// 		index 0 de lectura variable READ_END 
// 		index 1 de escritura variable WRITE_END
// 	*/
// 	int fd1[2];
// 	/* fd2
// 		fd que se utilizara para acceder
// 		al archivo dnd se quiere guardar la info
// 	*/
// 	int fd2;
// 	/* status
// 		se utliza para el wait que hace el padre
// 		y asi poder comunicar los procesos
// 	*/
// 	int status;
// 	/* pid	
// 		identificador de procesos de los hijos
// 	*/
// 	int pid;

// 	/* pipe()
// 		esta funcion crea una pipe y rellena 
// 		las 2 posiciones de fd1 con los files
// 		descriptors correspondientes
// 	*/
// 	pipe(fd1);
// 	/* fork
// 		nos crea el primer hijo
// 	*/
// 	pid = fork();
// 	if(pid == 0)//si pid es == 0 significa q es el hijo 1
// 	{
// 		//el hijo 1 ejecuta el primer comando (ls -l)
// 		close(fd1[READ_END]);//cerramos el extremo no necesario
// 		/*
// 			dup2 hace que cuando se una accion quiera usar
// 			el extremo de escritura STDOUT_FILENO redireccione
// 			la info a fd1[WRITE_END]
// 		*/
// 		dup2(fd1[WRITE_END], STDOUT_FILENO);
// 		close(fd1[WRITE_END]);//cerramos el extremo ESCRITURA
// 		//-------------------------------
// 		/*
// 		NO SE PUEDE USAR execlp() FUNION TENEMOS Q USAR execve()
// 			"/bin/ls" -> ruta de dnd se localiza el comando ls
// 			"ls" -> comando
// 			"-l" -> argumento de la funcion
// 			NULL -> para indicar q no mandamos mas arguments
// 		*/
// 		execlp("/bin/ls", "ls", "-l", NULL);
// 		// execve()

// 	}
// 	else// padre que genera un hijo
// 	{
// 		close(fd1[WRITE_END]);//cerramos el extremo no necesario
		
// 		/* fork
// 			nos crea el primer hijo
// 		*/
// 		pid = fork();//creacion del hijo
// 		if (pid == 0)
// 		{
// 			fd2 = open(FILE_NAME, O_WRONLY);//abrimos el archivo .txt
// 			// if (fd2 < 0)//ctr de errores
// 			// {
// 			// 	write(1, "asd\n", 4);
// 			// 	return(0);
// 			// }
// 			dup2(fd1[READ_END], STDIN_FILENO);//redireccionamos el estandar de lectura al fd1[Read]
// 			close(fd1[READ_END]);//lo cerramos pq no se utilizara mas

// 			dup2(fd2, STDOUT_FILENO);//redirecccionamos la respuesta del comando al archivo .txt
// 			execlp("/usr/bin/wc", "wc", NULL);//mismo funcionamientoo q el execlp de arriba
// 			ft_printf("Accede???\n");
// 		}
// 		else //SUPER-PADRE
// 		{
// 			close(fd1[READ_END]);//cerramos el extremo de lectura
// 		}
// 	}
// 	/*  Para esperar a los hijos */
// 	wait(&status);
// 	wait(&status);
// 	return(0);
// }

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
int main()
{
    int fd1[2];
    int fd2[2];
    int fd3;
    int status;
    int pid;

    //pipe comunicara proceso 1 y proceso 2
    //                  ls      y   grep
    pipe(fd1);
    pid = fork();
    if (pid == 0) //hijo 1
    {
        close(fd1[READ_END]);
        dup2(fd1[WRITE_END], STDOUT_FILENO);
        close(fd1[WRITE_END]);
        execlp("/bin/ls", "ls", "-l", NULL);
    }
    else //         super-padre
    {
        close(fd1[WRITE_END]);
        pipe(fd2);//comunica grep con wc (proceso 2 con proceso 3)
        pid = fork();
        if (pid == 0) //hijo 2
        {
            // close(fd2[WRITE_END]);
            dup2(fd1[READ_END], STDIN_FILENO);

            dup2(fd2[WRITE_END], fd1[READ_END]);
            fd3 = open(FILE_NAME, O_WRONLY );
            dup2(fd2[READ_END], STDIN_FILENO);
            dup2(fd3, STDOUT_FILENO);
            close(fd2[READ_END]);
            close(fd1[READ_END]);
            close(fd2[WRITE_END]);
            execlp("/bin/grep", "grep", "u", NULL);
        }
        else //padre
        {
            //----------------
            // close(fd1[READ_END]);
            // close(fd2[WRITE_END]);
            // pid = fork();
            // if (pid == 0)
            // {
            //     fd3 = open(FILE_NAME, O_WRONLY);
            //     dup2(fd3, STDOUT_FILENO);
            // }
            //----------------

            close(fd1[READ_END]);
            close(fd2[WRITE_END]);
            
            pid = fork();
            if (pid == 0)// hijo 3
            {
            //     dup2(fd2[READ_END], STDIN_FILENO);
            //     close(fd2[READ_END]);
            //     execlp("/usr/bin/wc", "wc", "-l", NULL);

                fd3 = open(FILE_NAME, O_WRONLY);
                dup2(fd2[READ_END], STDIN_FILENO);
                close(fd2[READ_END]);
                dup2(fd3, STDOUT_FILENO);
                execlp("/usr/bin/wc", "wc", "-l", NULL);

            }
        }
    }
    close(fd2[READ_END]);//cerramos el ultimo que quedaba
    //usamos wait para esperar a los hijos
    wait(&status);
    wait(&status);
    wait(&status);
    return(0);
}
