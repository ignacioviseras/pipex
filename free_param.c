/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:54:57 by igvisera          #+#    #+#             */
/*   Updated: 2024/07/28 19:02:49 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void free_param(t_params *p)
{
    free(p->comand_path1);
    free(p->comand_path2);
    free_all(p->comand1);
    free_all(p->comand2);
}
