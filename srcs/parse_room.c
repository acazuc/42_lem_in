/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:50:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/08 13:57:10 by acazuc           ###   ########.fr       */
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

int		parse_room(t_env *env, t_parser *p, char **split)
{
	if (!is_nbr(split[1]) || !is_nbr(split[2]))
		return (0);
}
