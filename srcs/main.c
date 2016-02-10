/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:04:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/10 11:37:44 by acazuc           ###   ########.fr       */
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
	parse(env);
	if (!env->start || !env->end)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	ft_putstr("Start room: ");
	ft_putendl(env->start ? env->start->name : "Empty");
	ft_putstr("End room: ");
	ft_putendl(env->end ? env->end->name : "Empty");
	place_pounds(env, env->end, 0);
	if (env->start->pound == INT_MAX)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	env->total_ants = env->ants;
	ft_putstr("Ants: ");
	ft_putnbr(env->ants);
	ft_putendl("\nRooms: ");
	t_room_list *lst;
	lst = env->rooms;
	while (lst)
	{
		ft_putchar('\'');
		ft_putstr(lst->room->name);
		ft_putstr("' pounded ");
		ft_putnbr(lst->room->pound);
		ft_putstr(" linked with: ");
		t_room_list *lst2;
		lst2 = lst->room->links;
		while (lst2)
		{
			ft_putstr(lst2->room->name);
			if (lst2->next)
				ft_putstr(", ");
			lst2 = lst2->next;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
	print_moves(env);
}
