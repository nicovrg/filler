/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:48:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/05 07:51:46 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		is_inmap(int y, int x, t_info *m)
{
	if (x > 0 && x < m->map_width && y > 0 && y < m->map_height)
		return (1);
	return (0);
}

int		compare_distance(int distance, t_play *p)
{
	if (distance <= p->best_distance)
	{
		if (p->map_x >= 0 && p->map_y >= 0)
		{
			p->best_distance = distance;
			p->map_fin_x = p->map_x;
			p->map_fin_y = p->map_y;
			return (1);
		}
	}
	return (0);
}

int		echo(int test, t_info *m, t_play *p)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (test > 0)
	{
		x = p->map_x;
		y = p->map_y;
		if (is_inmap(y - test, x + i, m) && m->map[y - test][x + i] == m->e_id)
			return (test);
		if (is_inmap(y + i, x + test, m) && m->map[y + i][x + test] == m->e_id)
			return (test);
		if (is_inmap(y + test, x - i, m) && m->map[y + test][x - i] == m->e_id)
			return (test);
		if (is_inmap(y - i, x - test, m) && m->map[y - i][x - test] == m->e_id)
			return (test);
		test--;
		i++;
	}
	return (0);
}

int		get_distance(t_info *m, t_play *p)
{
	int	test;
	int	distance;

	test = 0;
	distance = 10000;
	while (test < 10000)
	{
		if ((distance = echo(test, m, p)) != 0)
			return (compare_distance(distance, p));
		test++;
	}
	return (1);
}
