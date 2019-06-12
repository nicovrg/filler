/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 01:59:41 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/12 03:04:22 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

// int		dist_up(int test, t_info *m, t_play *p)
// {
// 	int	i;

// 	i = 0;
// 	while (test > 0)
// 	{
// 		if (m->map[p->map_x + i][p->map_y - test] == m->enemy_id)
// 			return (test);
// 		test--;
// 		i++;
// 	}
// }

// int		dist_right(int test, t_info *m, t_play *p)
// {
// 	int	i;

// 	i = 0;
// 	while (test > 0)
// 	{
// 		if (m->map[p->map_x + test][p->map_y + i] == m->enemy_id)
// 			return (test);
// 		test--;
// 		i++;
// 	}
// }

// int		dist_down(int test, t_info *m, t_play *p)
// {
// 	int	i;

// 	i = 0;
// 	while (test > 0)
// 	{
// 		if (m->map[p->map_x - i][p->map_y + test] == m->enemy_id)
// 			return (test);
// 		test--;
// 		i++;
// 	}
// }

// int		dist_left(int test, t_info *m, t_play *p)
// {
// 	int	i;

// 	i = 0;
// 	while (test > 0)
// 	{
// 		if (m->map[p->map_x - test][p->map_y - i] == m->enemy_id)
// 			return (test);
// 		test--;
// 		i++;
// 	}
// }