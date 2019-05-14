/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:23:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/14 02:59:13 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		write_piece_position(int x, int y)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
	write(1, "\n", 1);
	return (1);
}

int		get_dist_two(int distance, t_info *m, t_play *p)
{
	int i;
	int x;
	int y;

	i = 0;
	x = p->map_x + p->test_x;
	y = p->map_y + p->test_y;
	while (distance >= 0)
	{
		if ((y + distance < m->map_height && x + i < m->map_width && m->map[y + distance][x + i] == m->opponent_id)
		|| ((y - distance >= 0 && x + i < m->map_width && m->map[y - distance][x + i] == m->opponent_id))
		|| ((y + distance < m->map_height && x - i >= 0 && m->map[y + distance][x - i] == m->opponent_id))
		|| ((y - distance >= 0 && x - i >= 0 && m->map[y - distance][x - i] == m->opponent_id)))
			return (distance);
		i++;
		distance--;
	}
	return (0);
}

int		get_dist_one(t_info *m, t_play *p)
{
	int		distance;

	p->map_y = 0;
	while (p->map_y < m->piece_height)
	{
		p->map_x = 0;
		while (p->map_x < m->piece_width)
		{
			if (m->piece[p->map_y][p->map_x] == '*')
			{
				distance = 1;
				while (distance <= p->best_distance)
				{
					if (get_dist_two(distance, m, p) != 0 && distance < p->best_distance)
					{
						p->best_distance = distance;
						p->map_fin_x = p->map_x;
						p->map_fin_y = p->map_y;
					}
					distance++;
				}
			}
			p->map_x++;
		}
		p->map_y++;
	}
	return (1);
}

int		check_ally(t_info *m, t_play *p)
{
	int	x;
	int y;

	x = p->map_x + p->test_x;
	y = p->map_y + p->test_y;
	if (m->map[y][x] == m->player_id && m->piece[p->test_y][p->test_x] == '*')
		return (1);
	return (0);
}

int		check_opponent(t_info *m, t_play *p)
{
	int	x;
	int y;

	x = p->map_x + p->test_x;
	y = p->map_y + p->test_y;
	if (m->map[y][x] == m->opponent_id && m->piece[p->test_y][p->test_x] == '*')
		return (1);
	return (0);
}

int		check_limit(t_info *m, t_play *p)
{
	if (p->map_y + p->test_y >= m->map_height || p->map_x + p->test_x >= m->map_width)
		return (0);
	else if (p->map_y + p->test_y < 0 || p->map_x + p->test_x < 0)
		return (0);
	return (1);
}

int		check_place(t_info *m, t_play *p)
{
	int start;

	start = 0;
	p->test_y = -1;
	while (++p->test_y < m->piece_height)
	{
		p->test_x = -1;
		while (++p->test_x < m->piece_width)
		{
			if (!check_limit(m, p))
			{
				if (m->piece[p->test_y][p->test_x] == '*')
					return (0);
				else
					continue ;
			}
			if (check_ally(m, p) == 1)
				start++;
			if (check_opponent(m, p) == 1 || start > 1)
				return (0);
		}
	}
	return (start);
}

int		map_iterate(t_info *m, t_play *p)
{
	p->map_y = -m->piece_first_y;
	while (p->map_y < m->map_height)
	{
		p->map_x = -m->piece_first_x;
		while (p->map_x < m->map_width)
		{
			if (check_place(m, p) == 1)
				get_dist_one(m, p);
			p->map_x++;
		}
		p->map_y++;
	}
	return (1);
}

int		play(t_info *m, t_play *p)
{
	if (!map_iterate(m, p))
		return (ft_error("no place found for piece on map"));
	printf("p->map_fin_x = %d\np->map_fin_y = %d\n", p->map_fin_x, p->map_fin_y);
	write_piece_position(p->map_fin_x, p->map_fin_y);
	if (p->map_fin_x == 0 && p->map_fin_y == 0)
		return (0);
	return (1);
}
	// printf("%s\n", line);
	// write(1, "coucou\n", 7);