/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:18:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/08 18:19:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_LIST_H
# define ROOM_LIST_H

struct s_room;

typedef struct			s_room_list
{
	struct s_room		*room;
	struct s_room_list	*next;
}						t_room_list;

#endif
