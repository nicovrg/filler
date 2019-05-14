/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:02:56 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/15 01:30:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		allocate_piece(t_info *m)
{
	int i;

	i = 0;
	if (!(m->piece = (char **)malloc(sizeof(char *) * (m->piece_height + 1))))
		return (0);
	while (i < m->piece_height)
	{
		if (!(m->piece[i] = (char *)malloc(sizeof(char) * (m->piece_width + 1))))	
			return (0);
		i++;
	}
	m->piece[i] = 0;
	return (1);
}

int		check_piece_line(char *line, t_info *m)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (ft_error("invalid piece character - check_piece_line\n"));
		i++;
	}
	if (i != m->piece_width)
		return (ft_error("invalid piece size - check_piece_line\n"));
	return (1);
}

int		fill_piece(t_info *m)
{
	int 	i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < m->piece_height)
	{
		if (get_next_line(0, &line) <= 0)
			return (ft_error_free(&line, "problem in fill piece"));
		if (!check_piece_line(line, m))
			return (0);
		m->piece[i] = ft_strcpy(m->piece[i], line);
		i++;
	}
	if (i != m->piece_height)
		return (0);
	return (1);
}

int		get_corner(t_info *m)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < m->piece_height)
	{
		j = 0;
		while (j < m->piece_width)
		{
			if (m->piece[i][j] == '*' && k == 0)
			{
				m->piece_first_y = i;
				m->piece_first_x = j;
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		get_piece(t_info *m)
{
	int		i;
	char	*line;

	i = 6;
	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Piece ", 5))
			return (ft_error_free(&line, "Invalid syntaxe for \"Piece\""));
		if (!((m->piece_height = ft_atoi(line + i)) != 0))
			return (ft_error_free(&line, "Invalid piece height"));
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (!((m->piece_width = ft_atoi(line + i)) != 0))
			return (ft_error_free(&line, "Invalid piece width"));
		ft_strdel(&line);
	}
	else
		return (0);
	if (!allocate_piece(m) || !fill_piece(m) || !get_corner(m))
		return (ft_error("can't create piece"));
	return (1);
}
