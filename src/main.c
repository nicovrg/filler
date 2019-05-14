/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/14 02:31:54 by nivergne         ###   ########.fr       */
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
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
	return (1);
}

int		ft_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (0);
}

int		ft_error_free(char **line, char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	ft_strdel(line);
	return (0);
}

int		ft_error_free_tab(t_info *m, char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	if (m->map)
		ft_free_tab(m->map);
	if (m->piece)
		ft_free_tab(m->piece);
	return (0);
}

int		main(void)
{
	t_info	m;
	t_play	p;

	if (!init_struct(&m, &p))
		return (0);
	while (1)
	{
		p.best_distance = 2147483647;
		if (!fill_map(&m))
			return (ft_error_free_tab(&m, "problem in fill_map\n"));
		if (!get_piece(&m))
			return (ft_error_free_tab(&m, "problem in get_piece\n"));
		if (!play(&m, &p))
			break ;
		p.round++;
		ft_free_tab(m.piece);
	}
	ft_free_tab(m.map);
	ft_free_tab(m.piece);
	return (0);
}
