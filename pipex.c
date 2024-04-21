/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:20:46 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/21 19:44:54 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"

int main(int argc, char **argv, char **env)
{
    int x;
    int y;
    char **path;
    int fd;
    char *dir;

    x = 0;
    y = 0;
	printf("%d\n", argc);
	printf("%s\n\n----------\n\n", argv[1]);
    // paramvalidator(argc, argv);
    while (env[x])
    {
        if (ft_strncmp("PATH=", env[x], 5) == 0)
        {
        	printf("%s\n", env[x]);
            path = ft_split(env[x]+5, ':');
            while (path[y] || fd == 0)
            {
                dir = ft_strjoin(path[y], argv[2]);
            	// printf("Acces dir %s\n", dir);
                fd = access(dir, X_OK);
                if (fd == 0)
                {
                    printf("Tienes acceso\n");
                    break;
                }
            	// printf("%s\n", path[y]);
                y++;
            }
            printf("estado de acceso '%d'\n", fd);
            if (fd == -1)
            {
                printf("No hay accesso a ninugn directorio\n");
                exit(1);
            }
            
            return(0);
        }
        x++;
    }
    
	return (0);
}
