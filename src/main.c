/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/28 01:35:05 by nivergne         ###   ########.fr       */
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
	if (!(fd = open("test", O_WRONLY | O_APPEND)))
	{
		ft_putstr_fd("can not open file\n", fd);
		return (0);
	}

	if (!init_struct(&m, &p))
		return (ft_error("problem in init_struct\n"));
	if (!allocate_map(&m))
		return (ft_error_free_tab(&m, "error during map allocation\n"));
	while (1)
	{
		if (!init_round(&p))
			return (ft_error("problem in init_round\n"));
		if (!fill_map(&m, &p))
			return (ft_error_free_tab(&m, "problem in fill_map\n"));
		if (!get_piece(&m))
			return (ft_error_free_tab(&m, "problem in get_piece\n"));
		if (!play(&m, &p))
			break ;
		p.round++;
		ft_free_tab(&m.piece);
	}
	ft_free_tab(&m.map);
	close(fd);
	return (0);
}
