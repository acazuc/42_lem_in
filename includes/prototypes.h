/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:16:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/08 15:11:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"
# include "parser.h"

void	error_quit(char *str);
void	parse(t_env *env);
int		parse_room(t_env *env, t_parser *p, char **split);
int		parse_link(t_env *env, t_parser *p, char **split);
t_room	*room_create(void);

#endif
