/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:48:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/17 15:56:19 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		is_inmap(int x, int y, t_info *m)
{
	// printf("x = %d\ty = %d\twidth = %d\theight = %d\n", x, y, m->map_width, m->map_height);
	// if (x > 0 && x < m->map_width && y > 0 && y < m->map_height)
	if (x > 0 && x < m->map_height && y > 0 && y < m->map_width)
		return (1);
	return (0);
}

int		compare_distance(int distance, t_play *p)
{
	printf("p->map_fin_x = %d\n", p->map_fin_x);
	if (p->distance < p->best_distance)
	{
		p->best_distance = distance;
		p->map_fin_x = p->map_x;
		p->map_fin_y = p->map_y;
		printf("p->map_fin_x = %d\n", p->map_fin_x);
		printf("p->map_fin_y = %d\n", p->map_fin_y);
		return (1);
	}
	return (0);
}

int		echo(int test, t_info *m, t_play *p)
{
	int	i;

	i = 0;
	while (test > 0)
	{
		printf("test = %d\n", test);
		printf("x = %d\ty = %d\n", p->map_x + i, p->map_y - test);
		printf("x = %d\ty = %d\n", p->map_x + test, p->map_y + i);
		printf("x = %d\ty = %d\n", p->map_x - i, p->map_y + test);
		printf("x = %d\ty = %d\n\n", p->map_x - test, p->map_y - i);
		if (is_inmap(p->map_x + i, p->map_y - test, m) && m->map[p->map_x + i][p->map_y - test] == m->enemy_id)
			return (test);
		if (is_inmap(p->map_x + test, p->map_y + i, m) && m->map[p->map_x + test][p->map_y + i] == m->enemy_id)
			return (test);
		if (is_inmap(p->map_x - i, p->map_y + test, m) && m->map[p->map_x - i][p->map_y + test] == m->enemy_id)
			return (test);
		if (is_inmap(p->map_x - test, p->map_y - i, m) && m->map[p->map_x - test][p->map_y - i] == m->enemy_id)
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
		// printf(" ==== %s\n", m->map[15]);
		if ((distance = echo(test, m, p)) != 0)
			return (compare_distance(distance, p));
			// printf("DISTANCE =========== %d\n", distance);
		test++;
	}
	return (1);
}


		// printf("p->map_x + i = %d\tp->map_y - test = %d\n", p->map_x + i, p->map_y - test);
		// printf("p->map_x + test = %d\tp->map_y + i = %d\n", p->map_x + test, p->map_y + i);
		// printf("p->map_x - i = %d\tp->map_y + test = %d\n", p->map_x - i, p->map_y + test);
		// printf("p->map_x - test = %d\tp->map_y - i = %d\n\n", p->map_x - test, p->map_y - i);