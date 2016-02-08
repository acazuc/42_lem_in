/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:50:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/08 15:10:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_nbr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_start_end(t_env *env, t_room *room, t_parser *p)
{
	if (p->is_start)
	{
		if (env->start)
			return (0);
		env->start = room;
		p->is_start = 0;
	}
	else if (p->is_end)
	{
		if (env->end)
			return (0);
		env->end = room;
		p->is_end = 0;
	}
	return (1);
}

int		parse_room(t_env *env, t_parser *p, char **split)
{
	t_room	*room;

	if (!is_nbr(split[1]) || !is_nbr(split[2]))
		return (0);
	room = env->rooms;
	while (room)
	{
		if (!ft_strcmp(room->name, split[0]))
			return (0);
		room = room->next;
	}
	room = room_create();
	room->name = split[0];
	room->next = env->rooms;
	env->rooms = room;
	if (!check_start_end(env, room, p))
		return (0);
	return (1);
}
