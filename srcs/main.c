/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:04:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/09 10:29:30 by acazuc           ###   ########.fr       */
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
	ft_putstr("Ants: ");
	ft_putnbr(env->ants);
	ft_putendl("\nRooms: ");
	t_room_list *lst;
	lst = env->rooms;
	while (lst)
	{
		ft_putchar('\'');
		ft_putstr(lst->room->name);
		ft_putstr("' linked with: ");
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
	ft_putstr("Start room: ");
	ft_putendl(env->start ? env->start->name : "Empty");
	ft_putstr("End room: ");
	ft_putendl(env->end ? env->end->name : "Empty");
}
