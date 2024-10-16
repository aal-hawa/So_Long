/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:23:51 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/16 17:52:37 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_imgs_enemy(t_info *info)
{
	info->i_enemy = 0;
	info->ofset = 0;
	info->is_plus = 1;
	if (!info->enemes)
		return ;
	mlx_loop_hook(info->mlx, animited_enemy, &(*info));

}

int	main(int ac, char *arg)
{
	t_info info;
	int	fd;
	
	init_info(&info);
	if (ac != 2)
	{
		exitmassege("You Must Have One Map (chose_name.ber)\n", &info);
		exit (1);
	}
	info.is_bonus = 1;
	fd = open_map_fd(arg[1], &info);
	map_pars_main(fd, &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx,  info.sz * info.x_lngth_mp,  info.sz *  info.y_lngth_mp, "SO_LONG");
	put_imgs_to_wind(&info);
	put_imgs_enemy(&info);
	mlx_key_hook(info.win, keys_hook, &info);
	mlx_hook(info.win, 17, 0, close_win, &info);
	mlx_loop(info.mlx);
}
