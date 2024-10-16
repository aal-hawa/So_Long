/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:56 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/16 17:54:36 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_after_parse(t_info *info)
{
	if(info->cnt_collc == 0)
		exitmassege("You Must Have At Least One Collectible\n", info);
	if(info->is_hv_plr == 0)
		exitmassege("You Must Have A Player\n", info);
	if(info->is_hv_ext == 0)
		exitmassege("You Must Have A Exit\n", info);
}

void surrounded_map(char *test_line_map, t_info *info)
{
	int	i;

	i = 0;
	if (info->is_f_m_l == 0 || info->is_f_m_l == 2)
	{
		while (test_line_map[i])
		{
			if (test_line_map[i] != '1')
				exitmassege("You Must Arround The Map By Walls\n", info);
			i++;
		}
		info->is_f_m_l++;
	}
	if (test_line_map[0] != '1')
		exitmassege("You Must Arround The Map By Walls\n", info);
	if (test_line_map[ft_strlen(test_line_map) -1] != '1')
		exitmassege("You Must Arround The Map By Walls\n", info);
	
}

void	after_get_lines(int fd, t_info *info)
{
	check_after_parse(info);
	can_get_it(info, 't');
	can_get_it(info, 's');
	can_get_it(info, 'z');
	close(fd);
	if (info->is_hv_err == 1)
		exit (1);
}
void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

void	map_pars_main(int fd, t_info *info)
{
	char *test_line_map;
	
	while (1)
	{
		test_line_map = get_next_line(fd, info);
		if (!test_line_map)
			break;
		ft_strcpy(info->map[info->y_lngth_mp], test_line_map);
		info->y_lngth_mp++;
		if (info->y_lngth_mp > 27)
			exitmassege("The Length Of (y) It Must Less Or Equal 27\n", info);
		if (info->is_hv_err == 1)
			break ;
		if (info->x_lngth_mp == -1)
			info->x_lngth_mp = ft_strlen(test_line_map);
		data_map(test_line_map, info);
		surrounded_map(test_line_map, info);
		test_line_map = free_char(test_line_map);
		test_line_map = NULL;
	}
	after_get_lines(fd, info);
}



