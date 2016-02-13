/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:04:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/13 10:31:57 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		error_quit("Failed to malloc env");
	env->rooms = NULL;
	env->start = NULL;
	env->end = NULL;
	env->ants = -1;
	if (!(env->file = malloc(sizeof(*env->file))))
		error_quit("Failed to malloc env file lines");
	env->file[0] = NULL;
	parse(env);
	print_file(env);
	if (!env->start || !env->end || env->ants <= 0)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	place_pounds(env, env->end, 0);
	if (env->start->pound == INT_MAX)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	ft_putchar('\n');
	env->total_ants = env->ants;
	print_moves(env);
}
