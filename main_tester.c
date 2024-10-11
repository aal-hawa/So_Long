/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:48 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/11 19:25:22 by aal-hawa         ###   ########.fr       */
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
	info->y_length_line_map = -1;
	info->is_first_muddle_last = 0;
	info->x_win = 0;
	info->y_win = 0;
	info->size_img = 50;
	info->last_collc = 0;
}

int	main()
{
	t_info info;


	info.x= 0;
	info.y = 0;
	init_info(&info);
	map_pars_main(&info);
	
	info.mlx_ptr = mlx_init();
	mlx_get_color_value(info.mlx_ptr, 0x0000FF);
	info.data_addr = mlx_get_data_addr(info.img_ptr, &info.bits_per_pixel, &info.size_line, &info.endian);
	info.win_ptr = mlx_new_window(info.mlx_ptr,  info.size_img * info.x_length_line_map,  info.size_img *  info.y_length_line_map, "How Are You");
	
	// int ak = 200;
	// while (ak < 1000)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, ak++, 200, 0xFFFFFF);
	// img_ptr = mlx_new_image(mlx_ptr,  info.size_img,  info.size_img);
	put_imgs_to_wind(&info);
	// while(1)
	// {
	// 	info.img_ptr = mlx_xpm_file_to_image(info.mlx_ptr, "open.xpm", info.size_img, info.size_img);
	// 	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, info.x, info.y);

	// 	info.y+=info.bits_per_pixel;
	// 	if (info.y > info.size_line)
	// 	{
	// 		info.y = 0;
	// 		info.x +=info.bits_per_pixel;
	// 	}
	// 	if (info.x > info.size_line)
	// 		break ;
	// }
	mlx_key_hook(info.win_ptr, keys_hook, &info);
	mlx_loop(info.mlx_ptr);
}