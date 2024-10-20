/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:55 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 13:54:33 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_bonus_mlc(t_info *info)
{
	int			i;
	t_enemes	*enemes;
	t_enemes	*del_enemes;

	i = 0;
	while (info->m[i].m)
	{
		free(info->m[i].m);
		i++;
		if (i == 7)
			break ;
	}
	enemes = info->enemes;
	while (enemes->next)
	{
		del_enemes = enemes;
		enemes = enemes->next;
		free(del_enemes);
		del_enemes = NULL;
	}
}

int	close_win(t_info *info)
{
	if (info->img_wl)
		free(info->img_wl);
	if (info->img_wlk)
		free(info->img_wlk);
	if (info->img_plr)
		free(info->img_plr);
	if (info->img_collc)
		free(info->img_collc);
	if (info->img_ext)
		free(info->img_ext);
	if (info->is_bonus == 1)
		free_bonus_mlc(info);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

void	is_win(int y, int x, t_info *info)
{
	if (info->map[y][x] == 'E' && info->cnt_collc == 0)
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
