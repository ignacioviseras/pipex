/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:54:57 by igvisera          #+#    #+#             */
/*   Updated: 2024/08/02 17:27:16 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	free_param(t_params *p)
{
	free(p->comand_path1);
	free(p->comand_path2);
	free_all(p->comand1);
	free_all(p->comand2);
}
