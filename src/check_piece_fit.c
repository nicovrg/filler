/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece_fit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:53:31 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/20 01:12:45 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		check_ally(t_info *m, t_play *p)
{
	int	x;
	int	y;

	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	// printf("y = %d\tx = %d\tp->piece_y = %d\tp->piece_x = %d\tm->map_height = %d\tm->map_width = %d\tm->piece_height = %d\tm->piece_width = %d\n", y, x, p->piece_y, p->piece_x, m->map_height, m->map_width, m->piece_height, m->piece_width);
	if (y >= 0 && x >= 0 && y < m->map_height && x < m->map_width && p->piece_y >= 0 && p->piece_x >= 0 && p->piece_y < m->piece_height && p->piece_x < m->piece_width)
	{
		// printf("y = %d\tx = %d\tm->map[y][x] = %c\tm->piece[p->piece_y][p->piece_x] = %c\tp->piece_y = %d\tp->piece_x = %d\n", y, x, m->map[y][x], m->piece[p->piece_y][p->piece_x], p->piece_y, p->piece_x);
		if (m->map[y][x] == m->player_id && m->piece[p->piece_y][p->piece_x] == '*')
		{
			// printf("coucou\n");
			if (p->link == 0)
			{
				p->link++;
				return (1);
			}
			return (0);
		}
	}
	return (1);
}

int		check_enemy(t_info *m, t_play *p)
{
	int	x;
	int y;

	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	if (y >= 0 && x >= 0 && y < m->map_height && x < m->map_width)
	{
		if (m->map[y][x] == m->enemy_id && m->piece[p->piece_y][p->piece_x] == '*')
			return (1);
	}
	return (0);
}

int		check_limit(t_info *m, t_play *p)
{
	if (p->map_y + p->piece_y >= m->map_height)
		return (0);
	if (p->map_x + p->piece_x >= m->map_width)
		return (0);
	if (p->map_y + p->piece_y < 0)
		return (0);
	if (p->map_x + p->piece_x < 0)
		return (0);
	return (1);
}

int		check_place(t_info *m, t_play *p)
{
	p->link = 0;
	p->piece_y = 0;
	while (p->piece_y < m->piece_height)
	{
		p->piece_x = 0;
		while (p->piece_x < m->piece_width)
		{
			if (!check_limit(m, p) && m->piece[p->piece_y][p->piece_x] == '*')
			{
				// printf("check_limit has returned 0\n");
				return (0);
			}
			else if (!check_ally(m, p))
			{
				// printf("check_ally has returned 0\n");
				return (0);
			}
			else if (check_enemy(m, p) == 1)
			{
				// printf("check_enemy has returned 0\n");
				return (0);
			}
			p->piece_x++;
		}
		p->piece_y++;
	}
	// printf("p->link = %d\n", p->link);
	return (p->link);
}
