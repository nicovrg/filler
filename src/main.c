/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/05 11:04:04 by nivergne         ###   ########.fr       */
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

// void __attribute__((destructor)) end();
// void    end(void)
// {
// 	while(1);
// }

int		main(void)
{
	t_info	m;
	t_play	p;

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
			ft_free_tab(&m.piece);
			break ;
		}
		p.round++;
		ft_free_tab(&m.piece);
	}
	ft_free_tab(&m.map);
	return (0);
}
