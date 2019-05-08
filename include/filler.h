/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:09:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/08 15:51:18 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

typedef struct	s_info {
	char	player_id;
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
	int		round;
}				t_play;


//main.c
//for the moment, contain basics functions that could be added to libft
int		ft_isdigit_space(int c);
int		ft_free_tab(char **tab);
int		ft_error(char **line, char *error_msg);

//init.c
//get static information about the game: player_id, map_dimensions 
int		init_struct(t_info *m);
int		get_player_id(t_info *m);
int		get_map_dimensions(t_info *m);

//map.c
//allocate the map, check if lines are valid, fill the **map
int		allocate_map(t_info *m);
int		check_map_line(char **line, t_info *m);
int		fill_map(t_info *m);

//piece.c
//get dimensions, allocate the piece, check if it's valid, fill it
int		allocate_piece(t_info *m);
int		check_piece_line(char *line, t_info *m);
int		fill_piece(t_info *m);
int		get_piece(t_info *m);

//filler.c
int		play_round(t_info *m, t_play *p);

#endif