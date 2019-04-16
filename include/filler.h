/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:09:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/16 13:39:37 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

typedef struct	s_map {
	char	**map;
	int		map_width;
	int		map_height;
	int		player_id;
}				t_map;


#endif