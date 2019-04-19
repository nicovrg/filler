/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:21:25 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/20 00:05:41 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

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

int		check_line(char **line, t_map *m)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = *line;
	while (tmp[i] && ft_isdigit_space(tmp[i]) == 1)
		i++;
	if ((int)ft_strlen(tmp + i) != m->map_width)
	{
		ft_strdel(line);
		return (0);
	}
	while (tmp[i])
	{
		if (tmp[i] != 'O' && tmp[i] != 'X' && tmp[i] != '.')
		{
			ft_strdel(line);
			return (0);
		}
		i++;
	}
	return (1);
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
		if (!check_line(line, m))
			return (0);
		while (line[i] && ft_isdigit_space(line[i] == 1))
			i++;
		m->map[j] = ft_strcpy(m->map[j], line + i);
		ft_strdel(&line);
		j++;
		if (ft_atoi(line) == m->map_height - 1)
			break ;
	}
	m->map[j] = 0;
	return (1);
}
