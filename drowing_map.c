/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:58:05 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/13 19:12:31 by aal-hawa         ###   ########.fr       */
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

void	what_img_ptr(char char_pos, t_info *info)
{
	if (char_pos == '1')
		info->img_ptr = info->img_wall; 
	else if (char_pos == '0')
		info->img_ptr = info->img_walk;
	else if (char_pos == 'C')
		info->img_ptr = info->img_collc;
	else if (char_pos == 'P')
		info->img_ptr = info->img_player;
	else //if (char_pos == 'E')
		info->img_ptr = info->img_exit;
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
void	init_imgs(t_info *info)
{
	info->img_wall = mlx_xpm_file_to_image(info->mlx_ptr, "wall.xpm", &info->size_img, &info->size_img);
	if (info->img_wall == NULL)
		exitmassege("Something Happend Wrong With img_wall\n", info);
	info->img_walk = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
	if (info->img_walk == NULL)
		exitmassege("Something Happend Wrong With img_walk\n", info);
	info->img_player = mlx_xpm_file_to_image(info->mlx_ptr, "player.xpm", &info->size_img, &info->size_img);
	if (info->img_player == NULL)
		exitmassege("Something Happend Wrong With img_player\n", info);
	info->img_exit = mlx_xpm_file_to_image(info->mlx_ptr, "exit.xpm", &info->size_img, &info->size_img);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With img_exit\n", info);
	info->img_collc = mlx_xpm_file_to_image(info->mlx_ptr, "collc.xpm", &info->size_img, &info->size_img);
	if (info->img_collc == NULL)
		exitmassege("Something Happend Wrong With img_collc\n", info);
	if (info->is_have_error == 1)
		close_win(info);
}

void	put_imgs_to_wind(t_info *info)
{
	int	y;
	int	x;
	char name_img[100];
	int	is_save_data;
	
	y = 0;
	init_imgs(info);
	while (y < info->y_length_line_map)
	{
		x = 0;
		info->x = 0;
		while (x < info->x_length_line_map)
		{
			is_save_data = cpy_name_inmg(info->map[y][x], name_img, info);
			what_img_ptr(info->map[y][x], info);
			if (ft_strncmp(name_img, "walk.xpm", 9))
				mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk, info->x, info->y);
			is_save_pos_data(y, x, is_save_data, info);
			mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, info->x, info->y);
			info->x += info->size_img;
			x++;	
		}
		info->y += info->size_img;
		y++;
	}
}
