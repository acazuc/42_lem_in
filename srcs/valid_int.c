/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 09:30:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 09:40:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_int(char *line)
{
	while (*line == '0')
		line++;
	if (!ft_strisdigit(line))
		return (0);
	if (line[0] == '-')
		return (0);
	else if (ft_strlen(line) > 10)
		return (0);
	if (ft_atol(line) > INT_MAX)
		return (0);
	return (1);
}
