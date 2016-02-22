/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:04:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 09:37:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test_error(int i, char *error)
{
	if (i)
	{
		ft_putstr("Error: ");
		ft_putendl(error);
		exit(1);
	}
}

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
	ft_putchar('\n');
	test_error(!env->start, "No start room");
	test_error(!env->end, "No end room");
	test_error(env->ants <= 0, "Invalid ants number");
	place_pounds(env, env->end, 0);
	test_error(env->start->pound == INT_MAX, "No path available");
	env->total_ants = env->ants;
	print_moves(env);
}
