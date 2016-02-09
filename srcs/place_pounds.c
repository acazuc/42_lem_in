/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 10:32:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/09 11:36:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	place_pounds(t_env *env, t_room *room, int pound)
{
	t_room_list	*lst;

	if (pound < room->pound)
	{
		room->pound = pound;
		lst = room->links;
		while (lst)
		{
			place_pounds(env, lst->room, pound + 1);
			lst = lst->next;
		}
	}
}
