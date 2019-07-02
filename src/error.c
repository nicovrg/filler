/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 04:43:46 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/02 23:07:11 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (!*tab)
		return (0);
	while ((*tab)[i] != NULL)
	{
		ft_strdel(&(*tab)[i]);
		i++;
	}
	ft_memdel((void *)tab);
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
		ft_free_tab(&m->map);
	if (m->piece)
		ft_free_tab(&m->piece);
	return (0);
}
