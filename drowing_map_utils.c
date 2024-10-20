/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:08:06 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 13:53:46 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_img_enemy(t_info *info)
{
	info->i_enemy++;
	if (info->i_enemy == 7)
		info->i_enemy = 0;
	if (info->is_plus == 1)
		info->ofset += 4;
	else
		info->ofset -= 4;
	if (info->ofset >= 8)
		info->is_plus = -1;
	if (info->ofset <= -8)
		info->is_plus = 1;
}

int	animited_enemy(t_info *info)
{
	int			x;
	int			y;
	int			i;
	void		*m;
	t_enemes	*nxt_enemy;

	nxt_enemy = info->enemes;
	i = info->i_enemy;
	m = info->m[i].m;
	while (nxt_enemy)
	{
		x = nxt_enemy->x;
		y = nxt_enemy->y;
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, x
			* info->sz, y * info->sz);
		mlx_put_image_to_window(info->mlx, info->win, m, x * info->sz, (y
				* info->sz) + info->ofset);
		nxt_enemy = nxt_enemy->next;
	}
	change_img_enemy(info);
	return (0);
}

void	what_img_ptr(char char_pos, t_info *info)
{
	if (char_pos == '1')
		info->img = info->img_wl;
	else if (char_pos == '0')
		info->img = info->img_wlk;
	else if (char_pos == 'C')
		info->img = info->img_collc;
	else if (char_pos == 'P')
		info->img = info->img_plr;
	else if (char_pos == 'E')
		info->img = info->img_ext;
	else if (char_pos == 'e')
		info->img = info->m[0].m;
}
