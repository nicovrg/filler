/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:23:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/23 19:48:20 by nivergne         ###   ########.fr       */
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
