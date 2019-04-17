/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/17 23:33:12 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		init_struct(t_map *m)
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

int		get_player_id(t_map *m)
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
	m->player_id = line[10] == "1" ? 1 : 2;
	ft_strdel(&line);
	return (1);
}

int		get_map_dimensions(t_map *m)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	if (!get_next_line(0, &line) != 1)
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

int		allocate_map(t_map *m)
{
	int i;

	i = 0;
	if (!(m->map = (char **)malloc(sizeof(char *) * (m->map_height + 1))))
			return (0);
	while (i < m->map_height)
	{
		if (!(m->map[i] = (char *)malloc(sizeof(char) * (m->map_width + 1))))
			return (0);
		i++;
	}
	m->map[m->map_height] = 0;
	return (0);
}

int		check_line(char **line, t_map *map)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = *line;
	while (tmp[i] && (ft_isdigit(tmp[i]) == 1) || tmp[i] == ' ')
		i++;
	if ((int)ft_strlen(tmp + i) != map->map_width)
	{
		ft_strdel(line);
		return (0);
	}
	while (tmp[i])
	{
		if (tmp[i] != 'O' && tmp[i] != 'o' && tmp[i] != '.' && tmp[i] != 'X' && tmp[i] != 'x')
		{
			ft_strdel(line);
			return (0);
		}
		i++;
	}
	return (1);
}

int		write_line(char *line)
{
	if (!ft_check_line(&str, map))
		return (0);
	m->map[] = ft_strcpy(m->map[], line + ?);
}

int		fill_map(t_map *m)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "000", 3) == 0)
		{
			while (get_next_line(0, &line) > 0)
			{
				write_line(line);
			}
		}
		ft_strdel(&line);
		break ;
	}
	return (1);
}

int		main(void)
{
	t_map	m;

	if (!init_struct(&m))
		return (0);
	while (1)
	{
		if (!fill_map(&m))
			return (0);
	}
	return (0);
}
