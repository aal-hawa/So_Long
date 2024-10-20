/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:58:05 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 13:56:34 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs_bonus(t_info *info, int s)
{
	info->m[0].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/0.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[1].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/2.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[2].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/3.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[3].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/4.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[4].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/5.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[5].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/6.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
	info->m[6].m = mlx_xpm_file_to_image(info->mlx, "xpms/enm/7.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With enemy\n", info);
}

void	init_imgs(t_info *info)
{
	int	s;

	s = info->sz;
	info->img_wl = mlx_xpm_file_to_image(info->mlx, "xpms/wall.xpm", &s, &s);
	if (info->img_wl == NULL)
		exitmassege("Something Happend Wrong With wall.xpm\n", info);
	info->img_wlk = mlx_xpm_file_to_image(info->mlx, "xpms/walk.xpm", &s, &s);
	if (info->img_wlk == NULL)
		exitmassege("Something Happend Wrong With walk.xpm\n", info);
	info->img_plr = mlx_xpm_file_to_image(info->mlx, "xpms/player.xpm", &s, &s);
	if (info->img_plr == NULL)
		exitmassege("Something Happend Wrong With player.xpm\n", info);
	info->img_ext = mlx_xpm_file_to_image(info->mlx, "xpms/exit.xpm", &s, &s);
	if (info->img_ext == NULL)
		exitmassege("Something Happend Wrong With exit.xpm\n", info);
	info->img_collc = mlx_xpm_file_to_image(info->mlx, "xpms/collc.xpm", &s,
			&s);
	if (info->img_collc == NULL)
		exitmassege("Something Happend Wrong With collc.xpm\n", info);
	if (info->is_bonus == 1)
		init_imgs_bonus(info, s);
	if (info->is_hv_err == 1)
		close_win(info);
}

void	set_enemy_pos(int x, int y, t_info *info)
{
	t_enemes	*enemy;

	enemy = malloc(sizeof(t_enemes));
	if (!enemy)
	{
		exitmassege("error enemy malloc\n", info);
		return ;
	}
	enemy->x = x;
	enemy->y = y;
	enemy->next = info->enemes;
	info->enemes = enemy;
}

void	put_imgs_to_wind_2(int x, int y, t_info *info)
{
	int	s;

	s = info->sz;
	what_img_ptr(info->map[y][x], info);
	if (info->map[y][x] != '0')
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, x * s, y
			* s);
	if (info->map[y][x] == 'P')
	{
		info->x_plr = x;
		info->y_plr = y;
	}
	if (info->map[y][x] != 'e')
		mlx_put_image_to_window(info->mlx, info->win, info->img, x * s, y * s);
	else
		set_enemy_pos(x, y, info);
}

void	put_imgs_to_wind(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	init_imgs(info);
	while (y < info->y_lngth_mp)
	{
		x = 0;
		while (x < info->x_lngth_mp)
		{
			put_imgs_to_wind_2(x, y, info);
			x++;
		}
		y++;
	}
}
