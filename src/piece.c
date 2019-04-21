/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:02:56 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/21 16:04:44 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		allocate_fill_piece(t_map *m)
{
	int i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < m->piece_height && get_next_line(0, &line) > 0)
	{
		m->piece[i] = ft_strcpy(m->piece[i], line);
		i++;
	}
	if (i != m->piece_height)
		return (0);
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
	if (!allocate_fill_piece(m))
		return (0);
	return (1);
}
