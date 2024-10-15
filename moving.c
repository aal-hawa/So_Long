/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:24:07 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/15 18:31:54 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move_player(int y, int x, t_info *info)
{
	if (info->map[y][x] == '1')
		return (0);
	if (info->map[y][x] == 'E' && info->count_collectible != 0)
		return (0);
	if (info->map[y][x] == 'C')
	{
		info->count_collectible--;
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk, x * info->size_img, y * info->size_img);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_player, x * info->size_img, y * info->size_img);
	info->y_player = y;
	info->x_player = x;
	info->steps++;
	print_steps(info);
	is_win(info->y_player, info->x_player, info);
	is_lose(info->y_player, info->x_player, info);
	return (1);
}

void	move_up(t_info *info)
{
	int	is_moved;

	if (info->y_player == 0)
		return ;
	is_moved = check_move_player(info->y_player - 1, info->x_player, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk,  info->x_player * info->size_img, (info->y_player + 1) * info->size_img);
}

void	move_down(t_info *info)
{
	int	is_moved;

	if (info->y_player >= info->y_length_line_map)
		return ;
	is_moved = check_move_player(info->y_player + 1, info->x_player, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk,  info->x_player * info->size_img, (info->y_player - 1) * info->size_img);
}

void	move_right(t_info *info)
{
	int	is_moved;

	if (info->x_player >= info->x_length_line_map)
		return ;
	is_moved = check_move_player(info->y_player, info->x_player + 1, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk, ( info->x_player - 1) * info->size_img, info->y_player  * info->size_img);
}
void	move_left(t_info *info)
{
	int	is_moved;

	if (info->x_player == 0)
		return ;
	is_moved = check_move_player(info->y_player, info->x_player -1, info);
	if (is_moved == 1)
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk,  (info->x_player +1 )* info->size_img, info->y_player* info->size_img);
}
