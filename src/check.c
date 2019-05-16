/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:53:31 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/16 21:05:44 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		check_ally(t_info *m, t_play *p)
{
	int	x;
	int y;

	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	if (x >= 0 && y >= 0 && m->map[y][x] == m->player_id && m->piece[p->piece_y][p->piece_x] == '*')
		return (1);
	return (0);
}

int		check_opponent(t_info *m, t_play *p)
{
	int	x;
	int y;

	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
		// printf("m->map[y][x] = %c\ny = %d\nx = %d\n", m->map[y][x], y, x);
	if (x >= 0 && y >= 0 && m->map[y][x] == m->opponent_id && m->piece[p->piece_y][p->piece_x] == '*')
		return (1);
	return (0);
}

int		check_limit(t_info *m, t_play *p)
{
	if (p->map_y + p->piece_y >= m->map_height || p->map_x + p->piece_x >= m->map_width)
		return (0);
	else if (p->map_y + p->piece_y < 0 || p->map_x + p->piece_x < 0)
		return (0);
	return (1);
}

int		check_place(t_info *m, t_play *p)
{
	int start;

	start = 0;
	p->piece_y = -1;
	while (++p->piece_y < m->piece_height)
	{
		// printf("YYY  %d\n", p->piece_y);
		p->piece_x = -1;
		while (++p->piece_x < m->piece_width)
		{
			// printf("X    %d\n", p->piece_x);
			if (!check_limit(m, p))
			// {
				if (m->piece[p->piece_y][p->piece_x] == '*')
					return (0);
				// != *
				// else 
				// 	continue ;
			// }
			if (check_ally(m, p) == 1)
				start++;
			if (check_opponent(m, p) == 1 || start > 1)
				return (0);
		}
	}
	// printf("start = %d\n", start);
	return (start); //1
}
