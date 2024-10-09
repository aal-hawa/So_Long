/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:22:48 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/09 17:22:49 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	void * mlx_ptr;
	// void * win_ptr;
	// void *img_ptr;
	// // char *data_addr;
	// int bits_per_pixel;
	// int size_line;
	// int endian;
	// int x;
	// int y;

	// x= 0;
	// y = 0;

	mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 1800, 1920, "How Are You");
	// int ak = 200;
	// while (ak < 1000)
	// 	mlx_pixel_put(mlx_ptr, win_ptr, ak++, 200, 0xFFFFFF);
	// img_ptr = mlx_new_image(mlx_ptr, 200, 200);
	// // data_addr = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
	// mlx_get_color_value(mlx_ptr, 0x0000FF);
	







	// y+=50;
	// if (y > 1800)
	// {
	// 	y = 0;
	// 	x +=50;
	// }
	mlx_loop(mlx_ptr);
}