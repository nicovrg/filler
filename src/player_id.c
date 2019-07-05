/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:39:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/05 10:04:15 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		set_player_id(t_info *m, int ret)
{
	if (ret == 1)
	{
		m->p_id = 'O';
		m->e_id = 'X';
		return (1);
	}
	else if (ret == 2)
	{
		m->p_id = 'X';
		m->e_id = 'O';
		return (1);
	}
	return (0);
}

int		get_player_id(t_info *m)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	ret = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (ft_error("fail to read the first line\n"));
	if (ft_strncmp(line, "$$$ exec p", 10) != 0)
		return (ft_error_free(&line, "player format 0 is invalid\n"));
	while (!ft_isdigit(line[i]))
		i++;
	ret = ft_atoi(line + i);
	if (!set_player_id(m, ret))
		return (ft_error_free(&line, "player number is invalid\n"));
	if (ft_strncmp(line + i + 1, " : [", 3))
		return (ft_error_free(&line, "player format start is invalid\n"));
	while (line[i])
		i++;
	if (ft_strcmp(line + i - 1, "]"))
		return (ft_error_free(&line, "player format end is invalid\n"));
	ft_strdel(&line);
	return (1);
}
