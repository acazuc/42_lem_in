/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:11:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/21 15:04:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*room_create(void)
{
	t_room	*room;

	if (!(room = malloc(sizeof(*room))))
		error_quit("Failed to malloc room");
	room->name = NULL;
	room->links = NULL;
	room->pound = INT_MAX;
	return (room);
}
