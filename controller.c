/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:55 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/14 17:55:00 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	animited_enemy(t_info *info)
{
	int	i;
		
	i = info->i_enemy;
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk,  info->x_enemy * info->size_img,  info->y_enemy * info->size_img);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->enemy[i].img_enemy,  info->x_enemy * info->size_img, (info->y_enemy * info->size_img) + info->ofset);
	info->i_enemy++;
	if (info->i_enemy == 7)
		info->i_enemy = 0;
	if (info->is_plus == 1)
		info->ofset +=4;
		else
		info->ofset -=4;
	if (info->ofset >=8)
		info->is_plus = -1;
	if (info->ofset <=-8)
		info->is_plus = 1;;
	return (0);
}


int	close_win(t_info *info)
{
	int	i;
	
	if (info->img_wall)
		free(info->img_wall);
	if (info->img_walk)
		free(info->img_walk);
	if (info->img_player)
		free(info->img_player);
	if (info->img_collc)
		free(info->img_collc);
	if (info->img_exit)
		free(info->img_exit);
	if (info->is_Bonus == 1)
	{
		while (info->enemy[i].img_enemy)
		{
			free(info->enemy[i].img_enemy);
			i++;
			if (i == 7)
				break ;
		}
	}
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
	return (0);
}

void	is_win(int y, int x, t_info *info)
{
	if (info->map[y][x] == 'E' && info->count_collectible == 0)
	{
		ft_putstr_fd("YOU WON!!\n", 1, 0);
		close_win(info);
	}
}

void	is_lose(int y, int x, t_info *info)
{
	if (info->map[y][x] == 'e')
	{
		ft_putstr_fd("YOU LOSE!!\n", 1, 0);
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
		info->map[y][x] = '0';
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk, x * info->size_img, y * info->size_img);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_player, x * info->size_img, y * info->size_img);
	info->y_player = y;
	info->x_player = x;
	info->steps++;
	ft_putstr_fd("step: ", 1, 0);
	ft_putnbr_fd(info->steps,1, info);
	write(1, "\n", 1);
	if (info->is_Bonus == 1)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_wall, 0, 0);
		mlx_string_put(info->mlx_ptr, info->win_ptr,10,
			15, 0x00ffff, "step: ");
		info->is_for_bonus = 1;
		ft_putnbr_fd(info->steps,1, info);
		info->is_for_bonus = 0;
	}
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

int	keys_hook(int key_code, t_info *info)
{
	if (key_code == 13)
		move_up(info);
	else if (key_code == 1)
		move_down(info);
	else if (key_code == 2)
		move_right(info);
	else if (key_code == 0)
		move_left(info);
	else if (key_code == 53 || key_code == 17)
		close_win(info);
	return (0);
}


