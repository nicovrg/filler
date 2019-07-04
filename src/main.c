/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/03 02:52:26 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		ft_isdigit_space(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return (1);
	return (0);
}

int		main(void)
{
	t_info	m;
	t_play	p;

	int fd = 0;
	if (!(fd = open("test", O_WRONLY | O_APPEND | O_CREAT)))
	{
		ft_putstr("main - cant open file\n");
		return (0);
	}
	if (!init_struct(&m, &p))
		return (ft_error("main - error in init_struct\n"));
	if (!allocate_map(&m))
		return (ft_error_free_tab(&m, "main - error in allocate_map\n"));
	while (1)
	{
		if (!init_round(&p))
			return (ft_error("main - error in init_round\n"));
		if (!fill_map(&m, &p))
			return (ft_error_free_tab(&m, "main - error in fill_map\n"));
		if (!get_piece(&m))
			return (ft_error_free_tab(&m, "main - error in get_piece\n"));
		if (!play(&m, &p))
		{
			ft_putstr_fd("BREAK IN PLAY\n", fd);
			break ;
		}
		ft_putstr_fd("ROUND = ", fd);
		ft_putnbr_fd(p.round, fd);
		ft_putstr_fd("\n", fd);
		p.round++;
		ft_free_tab(&m.piece);
	}
	ft_free_tab(&m.map);
	close(fd);
	return (0);
}
