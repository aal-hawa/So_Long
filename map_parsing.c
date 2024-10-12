/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:56 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/12 13:07:36 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitmassege()
{
	ft_putstr_fd("DEFULT Error\n", 1, 0);
	ft_putstr_fd("============== DONT FORGET THE MALLOCS FREE ==============\n", 1, 0);
	exit(1);
}

void	data_map(char *test_line_map, t_info *info)
{
	if (ft_strlen(test_line_map) != info->x_length_line_map || ft_strlen(test_line_map) == 0)
		exitmassege();
	while(!test_line_map)
	{
		if (!(*test_line_map == '0' || *test_line_map == '1' || *test_line_map == 'C' || *test_line_map == 'E' || *test_line_map == 'P'))
			exitmassege();
		if ( *test_line_map == 'E')
		{
			if (info->is_have_exit == 1)
				exitmassege();
			info->is_have_exit = 1;
		}
		if ( *test_line_map == 'P')
		{
			if (info->is_have_palyer == 1)
				exitmassege();
			info->is_have_palyer = 1;
		}
		if ( *test_line_map == 'C')
			info->count_collectible ++;
		test_line_map++;
	}
	if(info->count_collectible == 0)
		exitmassege();
	if(info->is_have_palyer == 0)
		exitmassege();
	if(info->is_have_exit == 0)
		exitmassege();
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
				exitmassege();
			i++;
		}
		info->is_first_muddle_last++;
	}
	if (test_line_map[0] != '1')
		exitmassege();
	if (test_line_map[ft_strlen(test_line_map) -1] != '1')
		exitmassege();
}

void	map_pars_main(t_info *info)
{
	char *test_line_map;
	int	fd;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		exitmassege();
	ft_putstr_fd("aaaaaaa\n", 1, 0);
		
	}

	while (1)
	{
		test_line_map = get_next_line(fd, info);
		if (!test_line_map)
			break;

		
		ft_strcpy(info->map[info->y_length_line_map], test_line_map);
		info->y_length_line_map++;
		if (info->x_length_line_map == -1)
			info->x_length_line_map = ft_strlen(test_line_map);
		data_map(test_line_map, info);
		surrounded_map(test_line_map, info);
		
		test_line_map = free_char(test_line_map);
		test_line_map = NULL;
	}
}



