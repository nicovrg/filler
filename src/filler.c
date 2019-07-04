/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:23:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/04 06:27:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		write_piece_position(int x, int y)
{
	ft_putnbr(y);
	write (1, " ", 1);
	ft_putnbr(x);
	write (1, "\n", 1);
	return (0);
}

int		map_iterate(t_info *m, t_play *p)
{
	int fd = 0;
	if (!(fd = open("test", O_WRONLY | O_APPEND | O_CREAT)))
	{
		ft_putstr("cant open file\n");
		return (0);
	}
	p->map_y = m->piece_first_y;
	while (p->map_y < m->map_height)
	{
		p->map_x = m->piece_first_x;
		while (p->map_x < m->map_width)
		{
			if (check_place(m, p) == 1)
			{
				dprintf(fd, "\nMAP_ITERATE -\t\tplace found at y = %d x = %d\n", p->map_y, p->map_x);
				get_distance(m, p);
			}
			p->map_x++;
		}
		p->map_y++;
	}
	close(fd);
	return (1);
}

int		play(t_info *m, t_play *p)
{	
	int fd = 0;
	if (!(fd = open("test", O_WRONLY | O_APPEND | O_CREAT)))
	{
		ft_putstr("cant open file\n");
		return (0);
	}
	if (!map_iterate(m, p))
		return (ft_error("error in map_iterate"));
	write_piece_position(p->map_fin_x, p->map_fin_y);
	if (p->map_fin_x == 0 && p->map_fin_y == 0)
	{
		dprintf(fd, "p->map_fin_y = %d\tp->map_fin_x = %d\n", p->map_fin_y, p->map_fin_x);
		ft_putendl_fd("PLAY RETURN 0", fd);
		close(fd);
		return (0);
	}
	dprintf(fd, "p->map_fin_y = %d\tp->map_fin_x = %d\n", p->map_fin_y, p->map_fin_x);
	ft_putendl_fd("PLAY RETURN 1", fd);
	close(fd);
	return (1);
}
