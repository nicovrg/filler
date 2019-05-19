/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:21:25 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/19 22:33:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		allocate_map(t_info *m)
{
	int i;

	i = 0;
	if (!(m->map = (char **)ft_memalloc(sizeof(char *) * (m->map_height + 1))))
		return (0);
	while (i < m->map_height)
	{
		if (!(m->map[i] = (char *)ft_memalloc(sizeof(char) * (m->map_width + 1))))
			return (0);
		i++;
	}
	m->map[i] = 0;
	return (1);
}

int		check_map_line(char *line, t_info *m)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = line;
	while (tmp[i] && ft_isdigit_space(tmp[i]) == 1)
		i++;
	if ((int)ft_strlen(tmp + i) != m->map_width)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] != 'O' && tmp[i] != 'X' && tmp[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		fill_map(t_info *m)
{
	int		i;
	int		j;
	int		index_height;
	char	*line;

	i = 0;
	j = 0;
	index_height = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (ft_error_free(&line, "can't read map in fill_map\n"));
	ft_strdel(&line);
	while (index_height < m->map_height)
	{
		if (get_next_line(0, &line) <= 0)
			return (ft_error_free(&line, "can't read map in fill_map\n"));
		while (line[i] && ft_isdigit_space(line[i]) == 1)
			i++;
		if (!check_map_line(line + i, m))
			return (ft_error_free(&line, "wrong map line in fill_map\n"));
		m->map[j] = ft_strcpy(m->map[j], line + i);
		ft_strdel(&line);
		index_height++;
		j++;
	}
	m->map[j] = 0;
	return (1);
}
