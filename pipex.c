/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:20:46 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/22 17:55:01 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"

int main(int argc, char **argv, char **env)
{
    int x;

    x = 0;
	printf("%d\n", argc);
	printf("%s\n\n----------\n\n", argv[1]);
    // paramvalidator(argc, argv);
    while (env[x])
    {
        if (ft_strncmp("PATH=", env[x], 5) == 0)
        {
        	access_validate(env[x], argv[2]);
        	access_validate(env[x], argv[3]);
        }
        x++;
    }
    
	return (0);
}
