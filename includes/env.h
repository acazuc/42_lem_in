/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:16:42 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/10 10:59:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "room_list.h"
# include "room.h"

typedef struct		s_env
{
	t_room_list		*rooms;
	t_room			*start;
	t_room			*end;
	int				total_ants;
	int				ants;
}					t_env;

#endif
