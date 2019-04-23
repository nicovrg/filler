/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:09:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/23 19:49:24 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

typedef struct	s_info {
	int		player_id;
	int		map_width;
	int		map_height;
	char	**map;
	int		piece_width;
	int		piece_height;
	char	**piece;
}				t_info;

typedef struct	s_play {
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;
}				t_play;

//main.c
int		init_struct(t_info *m);
int		get_player_id(t_info *m);
int		get_map_dimensions(t_info *m);
int		get_piece(t_info *m);

//map.c
int		allocate_map(t_info *m);
int		check_line(char **line, t_info *m);
int		fill_map(t_info *m);

//piece.c
int		allocate_piece(t_info *m);
int		fill_piece(t_info *m);
int		get_piece(t_info *m);

//filler.c
int		ft_isdigit_space(int c);
int		ft_free_tab(char **tab);

#endif