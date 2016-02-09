/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:20:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/09 10:33:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

typedef struct			s_room
{
	char				*name;
	struct s_room_list	*links;
	int					pound;
}						t_room;

#endif
