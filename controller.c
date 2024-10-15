/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:55 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/15 18:38:50 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_bonus_mlc(t_info *info)
{
	int	i;
	t_enemes *enemes;
	t_enemes *del_enemes;
	
	while (info->m[i].m)
	{
		free(info->m[i].m);
		i++;
		if (i == 7)
			break ;
	}
	enemes = info->enemes;
	while (enemes)
	{
		del_enemes = enemes;
		enemes = enemes->next;
		free(del_enemes);
	}
}
int	close_win(t_info *info)
{
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
		free_bonus_mlc(info);
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


