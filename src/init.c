/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:54:41 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/05 02:55:00 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		init_struct(t_info *m, t_play *p)
{
	if (!get_player_id(m))
		return (ft_error("player_id is incorrect\n"));
	if (!get_map_dimensions(m))
		return (ft_error("map_dimensions incorrect\n"));
	if (!set_rest(m, p))
		return (ft_error("error while setting struct var to 0\n"));
	return (1);
}

int		get_player_id(t_info *m)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (ft_error("fail to read the first line\n"));
	// if (ft_strncmp(line, "$$$ exec p", 10) != 0)
		// return (ft_error_free(&line, "player format is invalid\n"));
	// printf("%s\n", line);
	if (line[12] && !(ft_strncmp(&line[12], "1", 1) == 0) && !(ft_strncmp(&line[12], "2", 1) == 0))
		return (ft_error_free(&line, "player number is invalid\n"));
	m->player_id = ft_strncmp(&line[12], "1", 1) == 0 ? 'O' : 'X';
	m->opponent_id = ft_strncmp(&line[12], "1", 1) == 0 ? 'X' : 'O';
	ft_strdel(&line);
	return (1);
}

int		get_map_dimensions(t_info *m)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (0);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	m->map_height = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	m->map_width = ft_atoi(line + i);
	ft_strdel(&line);
	return (1);
}

int		init_round(t_play *p)
{
	p->map_x = 0;
	p->map_y = 0;
	p->piece_x = 0;
	p->piece_y = 0;
	p->map_fin_x = 0;
	p->map_fin_y = 0;
	p->distance = 0;
	p->best_distance = 100;
	return (1);
}

int		set_rest(t_info *m, t_play *p)
{
	m->piece_width = 0;
	m->piece_height = 0;
	m->piece_first_x = 0;
	m->piece_first_y = 0;
	p->round = 0;
	p->map_x = 0;
	p->map_y = 0;
	p->piece_x = 0;
	p->piece_y = 0;
	p->map_fin_x = 0;
	p->map_fin_y = 0;
	p->distance = 0;
	return (1);
}
