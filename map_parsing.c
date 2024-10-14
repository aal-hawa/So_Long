/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:56 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/14 15:59:42 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitmassege(char *error, t_info *info)
{
	if (info->is_have_error == 1)
		return ;
	ft_putstr_fd("Error\n", 1, 0);
	ft_putstr_fd(error, 1, 0);
	ft_putstr_fd("DEFULT Error\n", 1, 0);
	
	ft_putstr_fd("============== DONT FORGET THE MALLOCS FREE ==============\n", 1, 0);
	info->is_have_error = 1;
	// exit(1);
}

void	data_map(char *test_line_map, t_info *info)
{
	int	x;

	x = 0;
	if (ft_strlen(test_line_map) != info->x_length_line_map || ft_strlen(test_line_map) == 0)
	{
		if(ft_strlen(test_line_map) == 0)
			exitmassege("It Must Not Empety\n", info);
		else
			exitmassege("It Must Rectangular\n", info);
	}
	if (ft_strlen(test_line_map) > 51)
		exitmassege("The Length Of (x) It Must Less Or Equal 52\n", info);
	if (info ->is_have_error == 1)
		return ;
	while(*test_line_map)
	{
		if (!(*test_line_map == '0' || *test_line_map == '1' || *test_line_map == 'C' || *test_line_map == 'E' || *test_line_map == 'P' || (*test_line_map == 'e' && info->is_Bonus == 1)))
			exitmassege("Invalid Input\n", info);
		if ( *test_line_map == 'E')
		{
			if (info->is_have_exit == 1)
				exitmassege("You Have More Than One Exit\n", info);
			info->is_have_exit = 1;
		}
		if ( *test_line_map == 'P')
		{
			if (info->is_have_palyer == 1)
				exitmassege("You Have More Than One Player\n", info);
			info->is_have_palyer = 1;
			info->x_player = x;
			info->y_player = info->y_length_line_map - 1;
		}
		if ( *test_line_map == 'C')
			info->count_collectible ++;
		test_line_map++;
		x++;
		if (info->is_have_error == 1)
			return ;
	}
}

void	check_after_parse(t_info *info)
{
	if(info->count_collectible == 0)
		exitmassege("You Must Have At Least One Collectible\n", info);
	if(info->is_have_palyer == 0)
		exitmassege("You Must Have A Player\n", info);
	if(info->is_have_exit == 0)
		exitmassege("You Must Have A Exit\n", info);
}
void flood(char **tab, t_point size, t_point cur, char to_flood)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y 
		|| tab[cur.y][cur.x] == to_flood || tab[cur.y][cur.x] == '1'
		|| (tab[cur.y][cur.x] == 'E' && to_flood == 's'))
		return ;
	
	tab[cur.y][cur.x] = to_flood;
	flood(tab, size,(t_point){cur.x +1, cur.y}, to_flood);
	flood(tab, size,(t_point){cur.x -1, cur.y}, to_flood);
	flood(tab, size,(t_point){cur.x, cur.y - 1}, to_flood);
	flood(tab, size,(t_point){cur.x, cur.y + 1}, to_flood);
}

void  flood_fill(char **tab, t_point size, t_point begin, char to_flood)
{
	flood(tab, size, begin, to_flood);
}

void	can_get_it(t_info *info, char to_flood)
{
	char **map;
	int	is_get;
	int i;
	int j;
	
	i = 0;
	map = malloc(sizeof(char *) * 100);
	while (i < 100)
	{
		map[i] = malloc(sizeof(char) * 100);
		i++;
	}
	j = 0;
	while (j < info->y_length_line_map)
	{
		i = 0;
		while (i < info->x_length_line_map)
		{
			map[j][i] = info->map[j][i];
			i++;
		}
		j++;
	}
	flood_fill(map, (t_point){info->x_length_line_map, info->y_length_line_map}, 
		(t_point){info->x_player, info->y_player}, to_flood);
	j = 0;
	while (j < info->y_length_line_map)
	{
		i = 0;
		while (i < info->x_length_line_map)
		{
			if ((map[j][i] == 'E' && to_flood == 't' ) || map[j][i] == 'C')
				exitmassege("Invalid Map\n", info);
			if (info->is_have_error == 1)
				break ;
			i++;
		}
		j++;
	}
	i = 0;
	while (i < 100)
	{
		free(map[i]);
		i++;
	}
	free(map);
}


void surrounded_map(char *test_line_map, t_info *info)
{
	int	i;

	i = 0;
	if (info->is_first_muddle_last == 0 || info->is_first_muddle_last == 2)
	{
		while (test_line_map[i])
		{
			if (test_line_map[i] != '1')
				exitmassege("You Must Arround The Map By Walls\n", info);
			i++;
		}
		info->is_first_muddle_last++;
	}
	if (test_line_map[0] != '1')
		exitmassege("You Must Arround The Map By Walls\n", info);
	if (test_line_map[ft_strlen(test_line_map) -1] != '1')
		exitmassege("You Must Arround The Map By Walls\n", info);
	
}

void	map_pars_main(t_info *info)
{
	char *test_line_map;
	int	fd;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		exitmassege("Error File Open\n", info);
	while (1)
	{
		test_line_map = get_next_line(fd, info);
		if (!test_line_map)
			break;
		ft_strcpy(info->map[info->y_length_line_map], test_line_map);
		
		info->y_length_line_map++;
		if (info->y_length_line_map > 27)
			exitmassege("The Length Of (y) It Must Less Or Equal 27\n", info);
		if (info->is_have_error == 1)
			break ;
		if (info->x_length_line_map == -1)
			info->x_length_line_map = ft_strlen(test_line_map);
		data_map(test_line_map, info);
		surrounded_map(test_line_map, info);
		test_line_map = free_char(test_line_map);
		test_line_map = NULL;
	}
	check_after_parse(info);
	can_get_it(info, 't');
	info->is_exit_as_wall = 1;
	can_get_it(info, 's');
	close(fd);
	if (info->is_have_error == 1)
		exit (1);
}



