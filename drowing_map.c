/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:58:05 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:42 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs_bonus(t_info *info, int s)
{
	info->m[0].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-0.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[1].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-2.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[2].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-3.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[3].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-4.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[4].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-5.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[5].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-6.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[6].m = mlx_xpm_file_to_image(info->mlx_ptr, "enemy-7.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
}

void	init_imgs(t_info *info)
{
	int	s;

	s = info->size_img;
	info->img_wall = mlx_xpm_file_to_image(info->mlx_ptr, "wall.xpm", &s, &s);
	if (info->img_wall == NULL)
		exitmassege("Something Happend Wrong With wall.xpm\n", info);
	info->img_walk = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &s, &s);
	if (info->img_walk == NULL)
		exitmassege("Something Happend Wrong With walk.xpm\n", info);
	info->img_player = mlx_xpm_file_to_image(info->mlx_ptr,
		"player.xpm", &s, &s);
	if (info->img_player == NULL)
		exitmassege("Something Happend Wrong With player.xpm\n", info);
	info->img_exit = mlx_xpm_file_to_image(info->mlx_ptr, "exit.xpm", &s, &s);
	if (info->img_exit == NULL)
		exitmassege("Something Happend Wrong With exit.xpm\n", info);
	info->img_collc = mlx_xpm_file_to_image(info->mlx_ptr,
		"collc.xpm", &s, &s);
	if (info->img_collc == NULL)
		exitmassege("Something Happend Wrong With collc.xpm\n", info);
	if(info->is_Bonus == 1)
		init_imgs_bonus(info, s);
	if (info->is_have_error == 1)
		close_win(info);
}

void	set_enemy_pos(int x, int y, t_info *info)
{
	t_enemes *enemy;
	
	enemy = malloc(sizeof(t_enemes));
	enemy->x = x;
	enemy->y = y;
	enemy->next = info->enemes;
	info->enemes = enemy;
	
}

void	put_imgs_to_wind_2(int x, int y, t_info *info)
{
	char name_img[100];
	int	is_save_data;
	
	is_save_data = cpy_name_inmg(info->map[y][x], name_img, info);
	what_img_ptr(info->map[y][x], info);
	if (ft_strncmp(name_img, "walk.xpm", 9))
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk, info->x, info->y);
	is_save_pos_data(y, x, is_save_data, info);
	if (is_save_data != 3)
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, info->x, info->y);
	else
		set_enemy_pos(x, y, info);
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
			put_imgs_to_wind_2(x, y, info);
			info->x += info->size_img;
			x++;	
		}
		info->y += info->size_img;
		y++;
	}
}
