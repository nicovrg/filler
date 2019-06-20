/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:48:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/20 05:14:39 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		is_inmap(int x, int y, t_info *m)
{
	if (x > 0 && x < m->map_height && y > 0 && y < m->map_width)
		return (1);
	return (0);
}

int		compare_distance(int distance, t_play *p)
{
	if (distance <= p->best_distance)
	{
		p->best_distance = distance;
		p->map_fin_x = p->map_x;
		p->map_fin_y = p->map_y;
		return (1);
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
		if (is_inmap(x + i, y - test, m) && m->map[x + i][y - test] == m->e_id)
			return (test);
		if (is_inmap(x + test, y + i, m) && m->map[x + test][y + i] == m->e_id)
			return (test);
		if (is_inmap(x - i, y + test, m) && m->map[x - i][y + test] == m->e_id)
			return (test);
		if (is_inmap(x - test, y - i, m) && m->map[x - test][y - i] == m->e_id)
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

	test = 1;
	distance = 0;
	while (distance == 0 && test < 100)
	{
		if ((distance = echo(test, m, p)) != 0)
			return (compare_distance(distance, p));
		test++;
	}
	return (1);
}
