/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/24 14:26:42 by nivergne         ###   ########.fr       */
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

int		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_strdel(tab[i]);
		i++;
	}
	ft_strdel(tab);
	return (1);
}

int		main(void)
{
	t_info	m;
	t_play	p;

	if (!init_struct(&m))
		return (0);
	while (1)
	{
		if (!fill_map(&m))
		{
			ft_free_tab(m.map);
			return (0);
		}
		if (!get_piece(&m))
		{
			ft_free_tab(m.map);
			ft_free_tab(m.piece);
			return (0);
		}
		if (!play_round(&m, &p))
			break ;
		p.round++;
	}
	ft_free_tab(m.map);
	ft_free_tab(m.piece);
	return (0);
}
