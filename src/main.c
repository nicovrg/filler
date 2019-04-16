/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/16 13:39:35 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		init_struct(t_map *map)
{
	if (!get_player_id(map))
	{
		write(2, "player_id incorrect\n", 20);
		return (0);
	}
	if (!get_map_dimensions(map))
	{
		write(2, "map_dimensions incorrect\n", 25);
		return (0);
	}
	if (!allocate_map(map))
	{
		write(2, "error during map allocation\n", 28);
		return (0);
	}
	return (1);
}

int		get_player_id(t_map *map)
{
	char *line;

	line = NULL;
	if (!get_next_line(0, &line) != 1)
		return (0);
	if (!strncmp(line, "$$$ exec p", 10))
	{
		ft_strdel(&line);
		return (0);
	}
	if (!line[10] || (line[10] && line[10] != "1" && line[10] != "2"))
	{
		ft_strdel(&line);
		return (0);
	}
	map->player_id = line[10] == "1" ? 1 : 2;
	ft_strdel(&line);
	return (1);
}

int		get_map_dimensions(t_map *map)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	if (!get_next_line(0, &line) != 1)
		return (0);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	map->map_height = ft_atoi(line + i);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	map->map_width = ft_atoi(line + i);
	ft_strdel(&line);
	return (1);
}

int		allocate_map(t_map *map)
{
	int i;

	i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * (map->map_height + 1))))
			return (0);
	while (i < map->map_height)
	{
		if (!(map->map[i] = (char *)malloc(sizeof(char) * (map->map_width + 1))))
			return (0);
		i++;
	}
	map->map[map->map_height] = 0;
	return (0);
}

int		main(void)
{
	t_map	map;

	if (!init_struct(&map))
		return (0);
	while (1)
	{

	}
	return (0);
}
