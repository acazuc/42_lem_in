/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 11:37:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/09 11:43:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_moves(t_env *env)
{
	t_room_list	*lst;
	t_room		*current;
	t_room		*best;

	while (env->ants > 0)
	{
		current = env->start;
		while (current != env->end)
		{
			best = NULL;
			lst = current->links;
			while (lst)
			{
				lst = lst->next;
			}
		}
		env->ants--;
	}
}
