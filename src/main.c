/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/19 00:29:37 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		ft_isdigit_space(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ') 
		return (1);
	return (0);
}

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

int		get_piece(t_map *m)
{
	int		i;
	char	*line;

	i = 5;
	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "Piece ", 5))
			return (0);
		if ((m->piece_height = ft_atoi(line + 5)) == 0)
			return (0);
		while (line[i] && ft_isdigit(line[i] == 1) && line[i] != ' ')
			i++;
		if ((m->piece_width = ft_atoi(line + 5)) == 0)
			return (0);		
	}
	while ()
	{

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
		if (!get_piece(&m))
			return (0);				
	}
	return (0);
}
