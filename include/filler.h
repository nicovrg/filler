/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:09:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/07 05:18:22 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

#include <stdio.h>

typedef struct	s_info 
{
	char	player_id;
	char	opponent_id;
	int		map_width;
	int		map_height;
	int		piece_width;
	int		piece_height;
	char	**map;
	char	**piece;
	int		piece_first_x;
	int		piece_first_y;
}				t_info;

typedef struct	s_play 
{
	int		round;
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;
	int		map_fin_x;
	int		map_fin_y;
	int		distance;
	int		best_distance;
}				t_play;

//main.c
//for the moment, contain basics functions that could be added to libft
int		ft_isdigit_space(int c);
int		ft_free_tab(char **tab);
int		ft_error(char *error_msg);
int		ft_error_free(char **line, char *error_msg);
int		ft_check_parse(t_info *m, t_play *p);

//init.c
//get static information about the game: player_id, map_dimensions 
int		init_struct(t_info *m, t_play *p);
int		check_player_name(char *line);
int		set_player_id(t_info *m, int ret);
int		get_player_id(t_info *m);
int		get_map_dimensions(t_info *m);
int		init_round(t_play *p);
int		set_rest(t_info *m, t_play *p);

//map.c
//allocate the map, check if lines are valid, fill the **map
int		allocate_map(t_info *m);
int		check_map_line(char *line, t_info *m);
int		fill_map(t_info *m);

//piece.c
//get dimensions, allocate the piece, check if it's valid, fill it
int		allocate_piece(t_info *m);
int		check_piece_line(char *line, t_info *m);
int		fill_piece(t_info *m);
int		get_corner(t_info *m);
int		get_piece(t_info *m);

//filler.c
//play, iteration on map, write position
int		write_piece_position(int x, int y);
int		map_iterate(t_info *m, t_play *p);
int		play(t_info *m, t_play *p);

//check.c
// check if we can place piece
int		check_place(t_info *m, t_play *p);
int		check_ally(t_info *m, t_play *p);
int		check_opponent(t_info *m, t_play *p);
int		check_limit(t_info *m, t_play *p);

//distance.c
// check distance from player piece vs opponent piece
int		get_dist_one(t_info *m, t_play *p);
int		get_dist_two(t_info *m, t_play *p);

#endif