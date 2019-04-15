/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:13:11 by nivergne          #+#    #+#             */
/*   Updated: 2019/04/15 19:20:29 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int     check_info_player(t_map *map)
{
    char *line;

    line = NULL;
    if (!get_next_line(0, &line) != 1)
        return (0);
    if (!strncmp(line, "$$$ exec p", 10))
    {
        ft_strdel(&line);
        return (0);
    }
    if (!line[10] || (line[10] && line[10] != "1" && line[10] != "2"))
    {
        ft_strdel(&line);
        return (0);
    }
    map->player_id = line[10] == "1" ? 1 : 2;
    ft_strdel(&line);
    return (1);
}

int     check_info_map(t_map *map)
{
    int i;
    char *line;

    i = 0;
    line = NULL;
    if (!get_next_line(0, &line) != 1)
        return (0);
    while (line[i] && !ft_isdigit(line[i]))
        i++;
    map->map_height = ft_atoi(line + i);
    while (line[i] && !ft_isdigit(line[i]))
        i++;
    map->map_width = ft_atoi(line + i);    
    ft_strdel(&line);
    return (1);
}

int     main(void)
{
            
    while (1)
    {

    }
    return (0);
}
