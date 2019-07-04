/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:21:25 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/03 02:59:14 by nivergne         ###   ########.fr       */
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
		if (!(m->map[i] = (char *)ft_memalloc(m->map_width + 1)))
			return (0);
		i++;
	}
	m->map[i] = NULL;
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

int		remove_line(char **line)
{
	if (get_next_line(0, line) <= 0)
		return (ft_error_free(line, "remove_line error\n"));
	ft_strdel(line);
	return (0);
}

int		init_fillmap(t_fillmap *f)
{
	f->i = 0;
	f->line = NULL;
	f->j = 0;
	f->map_height = 0;
	return (0);
}

int		fill_map(t_info *m, t_play *p)
{
	int fd = 0;
	if (!(fd = open("test", O_WRONLY | O_APPEND | O_CREAT)))
	{
		ft_putstr("cant open file\n");
		return (0);
	}
	t_fillmap	f;
	init_fillmap(&f);
	if (p->round != 0)
		remove_line((&f.line));
	if (get_next_line(0, &f.line) <= 0)
	{
		ft_putstr_fd("ERROR IN FILLMAP GNL\n", fd);
		return (ft_error_free(&f.line, "gnl after remove_line error\n"));
	}
	ft_strdel(&f.line);
	while (f.map_height < m->map_height)
	{
		if (get_next_line(0, &f.line) <= 0)
			return (ft_error_free(&f.line, "can't read map in fill_map\n"));
		ft_putendl_fd(f.line, fd);
		while (f.line[f.i] && ft_isdigit_space(f.line[f.i]) == 1)
			f.i++;
		if (!check_map_line(f.line + f.i, m))
			return (ft_error_free(&f.line, f.line));
		m->map[f.j] = ft_strcpy(m->map[f.j], f.line + f.i);
		ft_strdel(&f.line);
		f.map_height++;
		f.j++;
	}
	m->map[f.j] = 0;
	close(fd);
	return (1);
}
