/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:17 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/17 12:58:12 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitmassege(char *error, t_info *info)
{
	if (info->is_hv_err == 1)
		return ;
	ft_putstr_fd("Error\n", 1, 0);
	ft_putstr_fd(error, 1, 0);
	ft_putstr_fd("============== DONT FORGET THE MALLOCS FREE ==============\n", 1, 0);
	info->is_hv_err = 1;
	// exit(1);
}

void	after_can_get_it(t_info *info, char to_flood, char **map)
{
	int	j;
	int i;

	j = 0;
	flood_fill(map, (t_point){info->x_lngth_mp, info->y_lngth_mp}, 
		(t_point){info->x_plr, info->y_plr}, to_flood);
	while (j < info->y_lngth_mp)
	{
		i = 0;
		while (i < info->x_lngth_mp)
		{
			if ((map[j][i] == 'E' && to_flood == 't' ) || map[j][i] == 'C')
				exitmassege("Invalid Map\n", info);
			if (info->is_hv_err == 1)
				break ;
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 100)
		free(map[i++]);
	free(map);
}

void	can_get_it(t_info *info, char to_flood)
{
	char **map;
	// int	is_get;
	int i;
	int j;
	
	i = 0;
	map = malloc(sizeof(char *) * 100);
	if (!map)
		close_win(info);
	while (i < 100)
		map[i++] = malloc(sizeof(char) * 100);
	j = 0;
	while (j < info->y_lngth_mp)
	{
		i = 0;
		while (i < info->x_lngth_mp)
		{
			map[j][i] = info->map[j][i];
			i++;
		}
		j++;
	}
	after_can_get_it(info, to_flood, map);
}

void	chars_data_map(char c, int x, t_info *info)
{
		if (!(c == '0' || c == '1' || c == 'C' || c == 'E'
			|| c == 'P' || (c == 'e' && info->is_bonus == 1)))
			exitmassege("Invalid Input\n", info);
		if ( c == 'E')
		{
			if (info->is_hv_ext == 1)
				exitmassege("You Have More Than One Exit\n", info);
			info->is_hv_ext = 1;
		}
		if ( c == 'P')
		{
			if (info->is_hv_plr == 1)
				exitmassege("You Have More Than One Player\n", info);
			info->is_hv_plr = 1;
			info->x_plr = x;
			info->y_plr = info->y_lngth_mp - 1;
		}
		if ( c == 'C')
			info->cnt_collc ++;
}

void	data_map(char *test_line_map, t_info *info)
{
	int	x;

	x = 0;
	if (ft_strlen(test_line_map) != info->x_lngth_mp || ft_strlen(test_line_map) == 0)
	{
		if(ft_strlen(test_line_map) == 0)
			exitmassege("It Must Not Empety\n", info);
		else
			exitmassege("It Must Rectangular\n", info);
	}
	if (ft_strlen(test_line_map) > 51)
		exitmassege("The Length Of (x) It Must Less Or Equal 52\n", info);
	if (info ->is_hv_err == 1)
		return ;
	while(*test_line_map)
	{
		chars_data_map(*test_line_map, x, info);
		test_line_map++;
		x++;
		if (info->is_hv_err == 1)
			return ;
	}
}
