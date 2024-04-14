/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 11:47:55 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/14 17:34:58 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./pipex.h"


int argumentvalidator(char *str)
{
	printf("argumento '%s'\n", str);
	return (0);
}

/*
	@return
	- 0 its ok.
	@return
	-  -1 error.
*/
int paramvalidator(int argc, char **argv)
{
	int x;
	int validate;

	if (argc == 1)
	{
		printf("\t--- Error ---\nPasa algun argumento\n");
		return (-1);
	}
	x = 0;
	printf("numero de argumentos %i\n", argc);
	while (x < argc)
	{
		// printf("Argumento: %s\n", argv[x]);
		validate = argumentvalidator(argv[x]);
		if (validate == -1)
		{
			printf("\t--- Error ---\nArgumento invalido\n");
			return(-1);
		}
		x++;
	}

	return(0);
}
