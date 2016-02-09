/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 11:37:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/09 12:47:16 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*get_best(t_room *room)
{
	t_room_list	*lst;
	t_room		*best;

	best = NULL;
	lst = room->links;
	while (lst)
	{
		if (!best || best->pound > lst->room->pound)
			best = lst->room;
		lst = lst->next;
	}
	return (best);
}

void	print_moves(t_env *env)
{
	t_room		*current;

	while (env->ants > 0)
	{
		current = env->start;
		while (current != env->end)
		{
			current = get_best(current);
			ft_putchar('L');
			ft_putnbr(env->ants);
			ft_putchar('-');
			ft_putstr(current->name);
			if (current != env->end)
				ft_putchar(' ');
		}
		env->ants--;
		ft_putchar('\n');
	}
}
