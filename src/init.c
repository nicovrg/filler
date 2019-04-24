/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:54:41 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/24 13:54:56 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		init_struct(t_info *m)
{
	if (!get_player_id(m))
	{
		write(2, "player_id incorrect\n", 20);
		return (0);
	}
	if (!get_map_dimensions(m))
	{
		write(2, "map_dimensions incorrect\n", 25);
		return (0);
	}
	if (!allocate_map(m))
	{
		write(2, "error during map allocation\n", 28);
		return (0);
	}
	return (1);
}

int		get_player_id(t_info *m)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
	{
		write(1, "SHIT\n", 5);
		return (0);
	}
	if (!ft_strncmp(line, "$$$ exec p", 10))
	{
		ft_strdel(&line);
		return (0);
	}
	if (!line[10] || (line[10] && (ft_strncmp(line + 10, "1", 1) != 0 || ft_strncmp(line + 10, "2", 1) != 0)))
	{
		ft_strdel(&line);
		return (0);
	}
	m->player_id = ft_strncmp(line + 10, "1", 1) != 0 ? 'O' : 'X';
	ft_strdel(&line);
	return (1);
}

int		get_map_dimensions(t_info *m)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	if (!(get_next_line(0, &line) <= 0))
		return (0);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	m->map_height = ft_atoi(line + i);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	m->map_width = ft_atoi(line + i);
	ft_strdel(&line);
	return (1);
}