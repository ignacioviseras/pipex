/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+  	+#+           */
/*   Created: 2024/04/05 20:50:51 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/06 15:51:55 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef READ_END
#  define READ_END 0
# endif

# ifndef WRITE_END
#  define WRITE_END 1
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "./utils/utils.h"
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_params
{
	char		*file1;
	char		*file2;
	char		*comand_path1;
	char		*comand_path2;
	char		**comand1;
	char		**comand2;

}			t_params;

int		pipe_action(char *file1, char *file2, char *comand1, char *comand2);
char	*access_validate(char **path, char *comand);
char	*load_param(char **path, char *comand);
int		pipe_action(char *file1, char *file2, char *comand1, char *comand2);
int		red_flag_pipe(int *fd_pipe, int fd_file1, char *path, char **comand);
int		cigarette_pipe(int *fd_pipe, int fd_file2, char *path, char **comand);
int		initpipe(t_params *p);
int		tramited(char *path, char **arguments);
void	free_param(t_params *p);

#endif