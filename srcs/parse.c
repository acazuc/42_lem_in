/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:09:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/08 13:51:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_room(t_env *env, t_parser *p)
{
	char	**splitted;

	if (!(splitted = ft_strsplit(line, ' ')))
		error_quit("Failed to malloc split");
	if (splitted[0] && splitted[1] && splitted[2] && !splitted[3])
		return (parse_room(env, p, splitted));
	else if (splitted[0])
		return (0);
	return (1);
}

static int		check_link(t_env *env, t_parser *p)
{
	char	**splitted;

	if (!(splitter = ft_strsplit(line, '-')))
		error_quit("Failed to malloc split");
	if (splitted[0] && splitted[1] && !splitted[2])
		return (parse_link(env, p, splitted));
	else if (splitted[0])
		return (0);
	return (1);
}

static int		parse_line(t_env *env, t_parser *p)
{
	if (p->line[0] = '\0')
		return (1);
	if (p->line[0] == '#' && p-.line[1] == '#')
	{
		if (!ft_strcmp(p->line, "##start"))
		{
			if (p->is_start || p->is_end)
				return (0);
			p->is_start = 1;
		}
		else if (!ft_strcmp(p->line, "##end"))
		{
			if (p->is_start || p->is_end)
				return (0);
			p->is_end = 1;
		}
	}
	else
	{
		if (!check_room(env, parser))
			return (0);
		else if (!check_link(env, p))
			return (0);
	}
}

void	parse(t_env *env)
{
	char	*line;
	int		rd;

	while ((rd = get_next_line(0, &line)) == 1)
	{
		if (line[0] != '#' && line[1] && line[1] != '#')
			if (!parse_line(env, line))
				return ;
	}
	if (rd == -1)
		error_quit("Error while reading stdin");
}
