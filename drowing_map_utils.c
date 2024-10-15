/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:08:06 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/15 18:31:11 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_img_enemy(t_info *info)
{
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
		info->is_plus = 1;
}

int	animited_enemy(t_info *info)
{
	int	i;	// index_img
	int	x;
	int	y;
	void *m; // img
	t_enemes *nxt_enemy;

	nxt_enemy = info->enemes;
	i = info->i_enemy;
	m = info->m[i].m;
	while (nxt_enemy)
	{
		x = nxt_enemy->x;
		y = nxt_enemy->y;
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_walk,
			x * info->size_img,  y * info->size_img);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
			m, x * info->size_img,
			(y * info->size_img) + info->ofset);
		nxt_enemy = nxt_enemy->next;
	}
	change_img_enemy(info);
	return (0);
}

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
	else if (char_pos == 'E')
		ft_strcpy(name_img, "exit.xpm");
		else if (char_pos == 'e')
			return (ft_strcpy(name_img, "enemy-0.xpm"), 3);
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
	else if (char_pos == 'E')
		info->img_ptr = info->img_exit;
	else if (char_pos == 'e')
		info->img_ptr = info->m[0].m;
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
