/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:02:36 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/15 17:04:29 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_steps(t_info *info)
{
	char	str[12];

	if (info->is_Bonus == 1)
	{
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_wall, 0, 0);
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_wall, info->size_img, info->size_img);
		mlx_string_put(info->mlx_ptr, info->win_ptr, 10,
			15, 0x00ffff, "step: ");
		ft_putnbr_fd(info->steps,1, info);
		mlx_string_put(info->mlx_ptr, info->win_ptr, 80,
			15, 0x00ffff, ft_itoa_without_mlc(info->steps, str));
	}
	else
	{
		ft_putstr_fd("step: ", 1, 0);
		ft_putnbr_fd(info->steps,1, info);
		write(1, "\n", 1);
	}
}
