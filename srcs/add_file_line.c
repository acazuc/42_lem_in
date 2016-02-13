/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 10:24:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/13 10:28:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_file_line(t_env *env, char *line)
{
	char	**new;
	int		len;

	len = 0;
	while (env->file[len])
		len++;
	if (!(new = malloc(sizeof(*new) * (len + 2))))
		error_quit("Failed to malloc new lines tab");
	len = 0;
	while (env->file[len])
	{
		new[len] = env->file[len];
		len++;
	}
	new[len++] = line;
	new[len++] = NULL;
	free(env->file);
	env->file = new;
}
