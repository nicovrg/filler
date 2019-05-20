/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/20 17:00:38 by nivergne         ###   ########.fr       */
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
	if (!tab)
		return (0);
	while (tab[i] != 0)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_memdel((void *)&tab);
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
		return (ft_error("problem in init_struct\n"));
	if (!allocate_map(&m))
		return (ft_error_free_tab(&m, "error during map allocation\n"));
	// while (1)
	// {
		p.best_distance = 2147483647;
		if (!fill_map(&m))
			return (ft_error_free_tab(&m, "problem in fill_map\n"));
		if (!get_piece(&m))
			return (ft_error_free_tab(&m, "problem in get_piece\n"));
		// ft_check_parse(&m, &p);
		if (!play(&m, &p))
			// break ;
		p.round++;
		ft_free_tab(m.piece);
	// }
	ft_free_tab(m.map);
	return (0);
}

int		ft_check_parse(t_info *m, t_play *p)
{
	printf("m->player_id = %c\n", m->player_id);
	printf("m->opponent_id = %c\n", m->opponent_id);
	printf("\n");
	printf("m->map_height = %d\n", m->map_height);
	printf("m->map_width = %d\n", m->map_width);
	printf("\n");
	printf("m->piece_height = %d\n", m->piece_height);
	printf("m->piece_width = %d\n", m->piece_width);
	printf("\n");	
	printf("m->piece_first_x = %d\n", m->piece_first_x);
	printf("m->piece_first_y = %d\n", m->piece_first_y);
	printf("\n");
	printf("p->round = %d\n", p->round);
	printf("\n");	
	printf("p->map_x = %d\n", p->map_x);
	printf("p->map_y = %d\n", p->map_y);
	printf("\n");	
	printf("p->piece_x = %d\n", p->piece_x);
	printf("p->piece_y = %d\n", p->piece_y);
	printf("\n");
	printf("p->piece_x = %d\n", p->piece_x2);
	printf("p->piece_y = %d\n", p->piece_y2);
	printf("\n");
	printf("p->map_fin_x = %d\n", p->map_fin_x);
	printf("p->map_fin_y = %d\n", p->map_fin_y);
	printf("\n");
	printf("p->best_distance = %d\n", p->best_distance);
	return (1);
}
