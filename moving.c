/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:24:07 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 13:56:11 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move_player(int y, int x, t_info *info)
{
	if (info->map[y][x] == '1')
		return (0);
	if (info->map[y][x] == 'E' && info->cnt_collc != 0)
		return (0);
	if (info->map[y][x] == 'C')
	{
		info->cnt_collc--;
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, x
			* info->sz, y * info->sz);
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img_plr, x * info->sz, y
		* info->sz);
	info->y_plr = y;
	info->x_plr = x;
	info->steps++;
	print_steps(info);
	is_win(info->y_plr, info->x_plr, info);
	is_lose(info->y_plr, info->x_plr, info);
	return (1);
}

void	move_up(t_info *info)
{
	int	is_moved;

	if (info->y_plr == 0)
		return ;
	is_moved = check_move_player(info->y_plr - 1, info->x_plr, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, info->x_plr
			* info->sz, (info->y_plr + 1) * info->sz);
}

void	move_down(t_info *info)
{
	int	is_moved;

	if (info->y_plr >= info->y_lngth_mp)
		return ;
	is_moved = check_move_player(info->y_plr + 1, info->x_plr, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, info->x_plr
			* info->sz, (info->y_plr - 1) * info->sz);
}

void	move_right(t_info *info)
{
	int	is_moved;

	if (info->x_plr >= info->x_lngth_mp)
		return ;
	is_moved = check_move_player(info->y_plr, info->x_plr + 1, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk,
			(info->x_plr - 1) * info->sz, info->y_plr * info->sz);
}

void	move_left(t_info *info)
{
	int	is_moved;

	if (info->x_plr == 0)
		return ;
	is_moved = check_move_player(info->y_plr, info->x_plr - 1, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk,
			(info->x_plr + 1) * info->sz, info->y_plr * info->sz);
}
