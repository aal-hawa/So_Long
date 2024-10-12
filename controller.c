/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:55 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/12 21:29:42 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// change the value to be correct
enum 
{
	ON_W_PRESS = 13,
	ON_A_PRESS = 0,
	ON_S_PRESS = 1,
	ON_D_PRESS = 2,
	ON_EXIT_PRESS = 53,
	
};

void	close_win(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}

void	is_win(int y, int x, t_info *info)
{
	if (info->map[y][x] == 'E' && info->count_collectible == 0)
	{
		printf("YOU WON!!");
		close_win(info);
	}
}

int	check_move_player(int y, int x, t_info *info)
{
	if (info->map[y][x] == '1')
		return (0);
	if (info->map[y][x] == 'E' && info->count_collectible != 0)
		return (0);
	if (info->map[y][x] == 'C')
	{
		info->count_collectible--;
		mlx_destroy_image(info->mlx_ptr, info->collcs[info->collc_addr[y][x]]);
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, x * info->size_img, y * info->size_img);
	}
	mlx_destroy_image(info->mlx_ptr, info->img_player);
	info->img_player = NULL;
	info->img_player = mlx_xpm_file_to_image(info->mlx_ptr, "player.xpm", &info->size_img, &info->size_img);
	printf("x: %d\n", x);
	printf("y: %d\n", y);

	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_player, x * info->size_img, y * info->size_img);
	info->y_player = y;
	info->x_player = x;
	is_win(info->y_player, info->x_player, info);
	return (1);
}

void	move_up(t_info *info)
{
	int	is_moved;

	printf("info->y_player: %d\n", info->y_player);
	if (info->y_player == 0)
		return ;
	is_moved = check_move_player(info->y_player - 1, info->x_player, info);
	if (is_moved == 1)
	{
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr,  info->x_player * info->size_img, (info->y_player + 1) * info->size_img);
		printf(" info->x_player: %d\n",  info->x_player);
		printf("info->y_player: %d\n", info->y_player +1);
		printf(" info->size_img: %d\n",  info->size_img);

	}
		
}

void	move_down(t_info *info)
{
	int	is_moved;

	printf("info->y_player: %d\n", info->y_player);
	printf("info->y_length_line_map: %d\n", info->y_length_line_map);

	if (info->y_player >= info->y_length_line_map)
		return ;
	is_moved = check_move_player(info->y_player + 1, info->x_player, info);
	if (is_moved == 1)
	{
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr,  info->x_player * info->size_img, (info->y_player - 1) * info->size_img);
		printf(" info->x_player: %d\n",  info->x_player);
		printf("info->y_player: %d\n", info->y_player -1);
	}
}

void	move_right(t_info *info)
{
	int	is_moved;

	printf("info->x_player: %d\n", info->x_player);
	printf("info->x_length_line_map: %d\n", info->x_length_line_map);
	if (info->x_player >= info->x_length_line_map)
		return ;
	is_moved = check_move_player(info->y_player, info->x_player + 1, info);
	if (is_moved == 1)
	{
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, ( info->x_player - 1) * info->size_img, info->y_player  * info->size_img);
		printf(" info->x_player: %d\n",  info->x_player -1);
		printf("info->y_player: %d\n", info->y_player);
	}
}
void	move_left(t_info *info)
{
	int	is_moved;

	printf("info->x_player: %d\n", info->x_player);
	if (info->x_player == 0)
		return ;
	is_moved = check_move_player(info->y_player, info->x_player -1, info);
	if (is_moved == 1)
	{
		info->img_ptr = mlx_xpm_file_to_image(info->mlx_ptr, "walk.xpm", &info->size_img, &info->size_img);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr,  (info->x_player +1 )* info->size_img, info->y_player* info->size_img);
		printf(" info->x_player: %d\n",  info->x_player + 1);
		printf("info->y_player: %d\n", info->y_player);
	}
}

int	keys_hook(int key_code, t_info *info)
{
	printf("key_code number is %d: \n", key_code);
	if (key_code == 13)
		move_up(info);
	else if (key_code == 1)
		move_down(info);
	else if (key_code == 2)
		move_right(info);
	else if (key_code == 0)
		move_left(info);
	else if (key_code == 53)
		close_win(info);
	
	return (0);
}


