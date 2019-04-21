/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:09:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/21 16:02:46 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

typedef struct	s_map {
	int		player_id;
	int		map_width;
	int		map_height;
	char	**map;
	int		piece_width;
	int		piece_height;
	char	**piece;
}				t_map;

//main.c
int		init_struct(t_map *m);
int		get_player_id(t_map *m);
int		get_map_dimensions(t_map *m);
int		get_piece(t_map *m);

//map.c
int		allocate_map(t_map *m);
int		check_line(char **line, t_map *m);
int		fill_map(t_map *m);

#endif