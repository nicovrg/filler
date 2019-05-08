/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:02:56 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/08 16:55:46 by nivergne         ###   ########.fr       */
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
	m->piece[m->piece_height] = 0;
	return (1);
}

int		check_piece_line(char *line, t_info *m)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (0);
		i++;
	}
	if (i != m->piece_width)
		return (0);
	return (1);
}

int		fill_piece(t_info *m)
{
	int 	i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < m->piece_height && get_next_line(0, &line) > 0)
	{
		if (!check_piece_line(line, m))
			return (0);
		m->piece[i] = ft_strcpy(m->piece[i], line);
		i++;
	}
	if (i != m->piece_height)
		return (0);
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
		if (!ft_strncmp(line, "Piece ", 5))
			return (ft_error(&line, "Invalid syntaxe for \"Piece\""));
		if ((m->piece_height = ft_atoi(line + i)) == 0)
			return (ft_error(&line, "Invalid piece height"));
		while (line[i] && ft_isdigit(line[i] == 1))
			i++;
		if ((m->piece_width = ft_atoi(line + i)) == 0)
			return (ft_error(&line, "Invalid piece width"));
		ft_strdel(&line);
	}
	else
		return (0);
	if (!allocate_piece(m) || !fill_piece(m))
		return (0);
	return (1);
}
