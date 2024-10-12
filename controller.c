/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:55 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/12 13:00:13 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// change the value to be correct
enum 
{
	ON_W_PRESS = 1,
	ON_A_PRESS = 2,
	ON_S_PRESS = 3,
	ON_D_PRESS = 4,
	ON_EXIT_PRESS = 5,
	
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

void	check_move_player(int y, int x, t_info *info)
{
	if (info->map[y][x] == '1')
		return ;
	if (info->map[y][x] == 'E' && info->count_collectible != 0)
		return ;
	if (info->map[y][x] == 'C')
	{
		info->count_collectible--;
		mlx_destroy_image(info->mlx_ptr, info->collcs[info->collc_addr[y][x]]);
	}
	mlx_destroy_image(info->mlx_ptr, info->img_player);
	info->img_player = NULL;
	info->img_player = mlx_xpm_file_to_image(info->mlx_ptr, "player.xpm", &info->size_img, &info->size_img);
	info->y_player = y;
	info->x_player = x;
	is_win(info->y_player, info->x_player, info);
}

void	move_up(t_info *info)
{
	if (info->y_player == 0)
		return ;
	check_move_player(info->y_player - 1, info->x_player, info);
}

void	move_down(t_info *info)
{
	if (info->y_player >= info->y_length_line_map)
		return ;
	check_move_player(info->y_player + 1, info->x_player, info);
}

void	move_right(t_info *info)
{
	if (info->x_player >= info->x_length_line_map)
		return ;
	check_move_player(info->y_player, info->x_player + 1, info);
}
void	move_left(t_info *info)
{
	if (info->x_player == 0)
		return ;
	check_move_player(info->y_player, info->x_player -1, info);
}

int	keys_hook(int key_code, t_info *info)
{
	printf("key_code number is %d: \n", key_code);
	if (key_code == ON_W_PRESS)
		move_up(info);
	else if (key_code == ON_S_PRESS)
		move_down(info);
	else if (key_code == ON_D_PRESS)
		move_right(info);
	else if (key_code == ON_A_PRESS)
		move_left(info);
	else if (key_code == ON_EXIT_PRESS)
		close_win(info);
	
	return (0);
}


