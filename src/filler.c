/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:23:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/19 00:31:53 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		write_piece_position(int x, int y, int fd)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
	write(1, "\n", 1);

	ft_putnbr_fd(y, fd);
	write(fd, " ", 1);
	ft_putnbr_fd(x, fd);
	write(fd, "\n", 1);
	return (1);
}

// int		write_piece_position(int x, int y)
// {
// 	ft_putnbr(y);
// 	write(1, " ", 1);
// 	ft_putnbr(x);
// 	write(1, "\n", 1);
// 	return (1);
// }

int		map_iterate(t_info *m, t_play *p, __unused int fd)
{
	// write(fd, "ITER1\n", 6);
	p->map_y = -m->piece_first_y;
	// write(fd, "ITER2\n", 6);
	while (p->map_y < m->map_height)
	{
		// write(fd, "ITER3\n", 6);
		p->map_x = -m->piece_first_x;
		// write(fd, "ITER4\n", 6);
		while (p->map_x < m->map_width)
		{
			// write(fd, "ABCDE\n", 6);		
			if (check_place(m, p) == 1)
			{
				// write(fd, "ABCD5\n", 6);
				get_distance(m, p);
			}
			p->map_x++;
		}
		// write(fd, "ITER5\n", 6);
		p->map_y++;
	}
	// write(fd, "ITER6\n", 6);
	return (1);
}

int		play(t_info *m, t_play *p, int fd)
{
	// write(fd, "PLAY0\n", 6);
	if (!map_iterate(m, p, fd))
		return (ft_error("no place found for piece on map"));
	// write(fd, "PLAY1\n", 6);
	write_piece_position(p->map_fin_x, p->map_fin_y, fd);
	// write(fd, "PLAY2\n", 6);
	if (p->map_fin_x == 0 && p->map_fin_y == 0)
		return (0);
	return (1);
}
