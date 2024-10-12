/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:56 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/12 19:42:37 by aal-hawa         ###   ########.fr       */
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
		// ft_putstr_fd("a1......\n", 1, 0);
		// ft_putstr_fd("test_line_map\n", 1, 0);
		// ft_putstr_fd("a1......\n", 1, 0);
		// printf("info->x_length_line_map;;;;;; %d\n", info->x_length_line_map);
		// printf("ft_strlen(test_line_map) %d\n", ft_strlen(test_line_map) );

	if (ft_strlen(test_line_map) != info->x_length_line_map || ft_strlen(test_line_map) == 0)
		exitmassege();
		ft_putstr_fd("a5615901891021\n", 1, 0);

	while(*test_line_map)
	{
		ft_putstr_fd("a1\n", 1, 0);
		printf("info->x_length_line_map;;;;;; %d\n", info->x_length_line_map);
		printf("ft_strlen(test_line_map) %d\n", ft_strlen(test_line_map) );
		printf("*test_line_map) %d\n", *test_line_map );
		if (!(*test_line_map == '0' || *test_line_map == '1' || *test_line_map == 'C' || *test_line_map == 'E' || *test_line_map == 'P'))
			exitmassege();
		ft_putstr_fd("a2\n", 1, 0);

		if ( *test_line_map == 'E')
		{
		ft_putstr_fd("a3\n", 1, 0);
			
			if (info->is_have_exit == 1)
				exitmassege();
		ft_putstr_fd("a4\n", 1, 0);

			info->is_have_exit = 1;
		}
		ft_putstr_fd("a5\n", 1, 0);

		if ( *test_line_map == 'P')
		{
		ft_putstr_fd("a6\n", 1, 0);

		if (info->is_have_palyer == 1)
			exitmassege();
		ft_putstr_fd("a7\n", 1, 0);

			info->is_have_palyer = 1;
		}
		if ( *test_line_map == 'C')
			info->count_collectible ++;
		test_line_map++;
	}

		
}

void	check_after_parse(t_info *info)
{
		if(info->count_collectible == 0)
		exitmassege();
	ft_putstr_fd("a8\n", 1, 0);
		
	if(info->is_have_palyer == 0)
		exitmassege();
	ft_putstr_fd("a9\n", 1, 0);

	if(info->is_have_exit == 0)
		exitmassege();
	ft_putstr_fd("a10\n", 1, 0);
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

		ft_putstr_fd("aaaaaaa11\n", 1, 0);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{

		exitmassege();
		ft_putstr_fd("aaaaaaa\n", 1, 0);
		
	}
		ft_putstr_fd("aaaaaaa112\n", 1, 0);

	while (1)
	{
		ft_putstr_fd("aaaaaaa113\n", 1, 0);

		test_line_map = get_next_line(fd, info);
		ft_putstr_fd("aaaaaaa114\n", 1, 0);

		if (!test_line_map)
			break;

		ft_putstr_fd("aaaaaaa115\n", 1, 0);
			printf("55: info->y_length_line_map;;;;;; %d\n", info->y_length_line_map);
		ft_strcpy(info->map[info->y_length_line_map], test_line_map);
		ft_putstr_fd("aaaaaaa116\n", 1, 0);

		info->y_length_line_map++;
		printf("2: info->x_length_line_map;;;;;; %d\n", info->x_length_line_map);
		if (info->x_length_line_map == -1)
			info->x_length_line_map = ft_strlen(test_line_map);
		printf("2: info->x_length_line_map;;;;;; %d\n", info->x_length_line_map);
		printf("2: ft_strlen(test_line_map) %d\n", ft_strlen(test_line_map) );

		ft_putstr_fd("aaaaaaa117\n", 1, 0);
			
		data_map(test_line_map, info);
		ft_putstr_fd("aaaaaaa118\n", 1, 0);

		ft_putstr_fd("aaaaaaa119\n", 1, 0);
		surrounded_map(test_line_map, info);
		
		test_line_map = free_char(test_line_map);
		test_line_map = NULL;
	}
	check_after_parse(info);
	ft_putstr_fd("a111111\n", 1, 0);

}



