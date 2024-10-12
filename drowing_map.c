/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:58:05 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/12 21:37:10 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	cpy_name_inmg(char char_pos, char *name_img, t_info *info)
{
	if (char_pos == '1')
		ft_strcpy(name_img, "wall.xpm");
	else if (char_pos == '0')
		ft_strcpy(name_img, "walk.xpm");
	else if (char_pos == 'C')
		return (ft_strcpy(name_img, "collc.xpm"), 1);
	else if (char_pos == 'P')
		return (ft_strcpy(name_img, "player.xpm"), 2);
	else //if (char_pos == 'E')
		ft_strcpy(name_img, "exit.xpm");
	return (0);
}
void	is_save_pos_data(int y, int x, int number_save, t_info *info)
{
	if (number_save == 1)
	{
		info->collc_addr[y][x] = info->last_collc;
		info->collcs[info->last_collc] = info->img_ptr;
		info->last_collc++;
	}
	if (number_save == 2)
	{
		info->x_player = x;
		info->y_player = y;
		info->img_player = info->img_ptr;
	} 
}
void	put_imgs_to_wind(t_info *info)
{
	int	y;
	int	x;
	char name_img[100];
	int	is_save_data;
	
	y = 0;

	while (y < info->y_length_line_map)
	{
		
		x = 0;
		info->x = 0;
		while (x < info->x_length_line_map)
		{
			is_save_data = cpy_name_inmg(info->map[y][x], name_img, info);
			if (ft_strncmp(name_img, "walk.xpm", 9))
			{
				info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, info->x, info->y);
			}
			is_save_pos_data(y, x, is_save_data, info);
			info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, name_img, &info->size_img, &info->size_img);
			mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, info->x, info->y);
			info->x += info->size_img;
			x++;	
		}

		info->y += info->size_img;
		y++;
	}
}
