/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:50:51 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/06 15:51:55 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#ifndef READ_END
# define READ_END 0 /* PIPE EXTREMO DE LECTURA */
#endif

#ifndef WRITE_END
# define WRITE_END 1 /* PIPE EXTREMO DE ESCRITURA */
#endif

#ifndef FILE_NAME
# define FILE_NAME "result.txt" /* NOMBRE DEL ARCHIVO DND SE GUARDA LA INFO */
#endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

#include <unistd.h>
#include <stdlib.h>
#include "./utils/utils.h"

int		paramvalidator(int argc, char **argv);
int filesvalidator(char *file1, char *file2);
int access_validate(char *env, char *comand);


#endif