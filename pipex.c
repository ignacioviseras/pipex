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

#include "pipex.h"

int main()
{
    //fd 0 es el de lectura
    //fd 1 es el de escritura 
    int fd[2];
    pid_t pidC;
    int num;//n de byte leidos
    char bf[10];//aqui es dnd se almacena el mensaje (le estoy fozando 10 caracteres ahora mismo)

    pipe(fd); //need to add control errors
    pidC = fork();
    if (pidC == 0) // hijo
    {
        close(fd[0]);//cerramos el fd de leer
        write(fd[1], "acede al hijo\n", 15);
        close(fd[1]);//cerramos el fd de escritura
        exit(0);
    }
    else if (pidC == -1)//error
        return;
    else // padre
        close(fd[1]);//cerramos el fd de escritura
        read(fd[0], bf, sizeof(bf));
        close(fd[0]);//cerramos el fd de leer
        return;

}
