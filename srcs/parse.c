/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:09:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/13 10:25:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_room(t_env *env, t_parser *p)
{
	char	**splitted;

	if (!(splitted = ft_strsplit(p->line, ' ')))
		error_quit("Failed to malloc split");
	if (splitted[0] && splitted[1] && splitted[2] && !splitted[3])
		return (parse_room(env, p, splitted));
	else if (splitted[0] && splitted[1])
		return (0);
	return (-1);
}

static int		check_link(t_env *env, t_parser *p)
{
	char	**splitted;

	if (!(splitted = ft_strsplit(p->line, '-')))
		error_quit("Failed to malloc split");
	if (splitted[0] && splitted[1] && !splitted[2])
		return (parse_link(env, p, splitted));
	else if (splitted[0] && splitted[1])
		return (0);
	return (-1);
}

static int		check_start_end(t_env *env, t_parser *p)
{
	if (!ft_strcmp(p->line, "##start"))
	{
		if (p->is_start || p->is_end || env->start)
			return (0);
		p->is_start = 1;
	}
	else if (!ft_strcmp(p->line, "##end"))
	{
		if (p->is_start || p->is_end || env->end)
			return (0);
		p->is_end = 1;
	}
	return (1);
}

static int		parse_line(t_env *env, t_parser *p)
{
	int		c_r;
	int		c_l;

	if (p->line[0] == '\0')
		return (0);
	if (p->line[0] == '#' && p->line[1] == '#')
	{
		if (!check_start_end(env, p))
			return (0);
	}
	else
	{
		if (!(c_r = check_room(env, p)))
			return (0);
		else if (!(c_l = check_link(env, p)))
			return (0);
		if (c_r == -1 && c_l == -1)
			return (0);
		
	}
	return (1);
}

void	parse(t_env *env)
{
	t_parser	p;
	int			rd;

	p.is_start = 0;
	p.is_end = 0;
	while ((rd = get_next_line(0, &(p.line))) == 1)
	{
		add_file_line(env, p.line);
		if (p.line[0] != '#' || (p.line[1] && p.line[1] == '#'))
		{
			if (env->ants == -1)
			{
				if (ft_strisdigit(p.line))
					env->ants = ft_atoi(p.line);
				else
					return ;
			}
			else if (!parse_line(env, &p))
				return ;
		}
	}
	if (rd == -1)
		error_quit("Error while reading stdin");
}
