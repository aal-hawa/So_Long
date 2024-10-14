/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:48 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/14 17:55:07 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info)
{
	info->is_have_palyer = 0;
	info->is_have_exit = 0;
	info->count_collectible = 0;
	info->is_arround_wall = 0;
	info->x_length_line_map = -1;
	info->y_length_line_map = 0;
	info->is_first_muddle_last = 0;
	info->x_win = 0;
	info->y_win = 0;
	info->size_img = 50;
	info->last_collc = 0;
	info->is_have_error = 0;
	info->steps = 0;
	info->is_exit_as_wall = 0;
	info->is_Bonus = 1;
	info->i_enemy = 0;
	info->ofset = 0;
	info->is_for_bonus = 0;

}

int	main()
{
	t_info info;

	info.x= 0;
	info.y = 0;
	init_info(&info);
	map_pars_main(&info);
	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr,  info.size_img * info.x_length_line_map,  info.size_img *  info.y_length_line_map, "SO_LONG");
	put_imgs_to_wind(&info);
	mlx_key_hook(info.win_ptr, keys_hook, &info);
	mlx_hook(info.win_ptr, 17, 0, close_win, &info);
	if(info.is_Bonus == 1)
	{
		// mlx_loop_hook(info.img_ptr, animited_enemy, &info);
	}
	mlx_loop(info.mlx_ptr);

}
