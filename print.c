/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:16 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/20 13:55:45 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	len_itoa(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa_without_mlc(int n, char *str)
{
	size_t	len;

	if (n == -2147483648)
		return ("-2147483648");
	len = len_itoa(n);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

void	recursive_nbr(int n, int fd)
{
	char	c;

	if (n < 0)
		return ;
	if (n > 9)
	{
		recursive_nbr(n / 10, fd);
		recursive_nbr(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	recursive_nbr(n, fd);
}

void	print_steps(t_info *info)
{
	char	str[12];

	if (info->is_bonus == 1)
	{
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, 0, 0);
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, info->sz,
			0);
		mlx_put_image_to_window(info->mlx, info->win, info->img_wlk, 2
			* info->sz, 0);
		mlx_put_image_to_window(info->mlx, info->win, info->img_wl, 0, 0);
		mlx_put_image_to_window(info->mlx, info->win, info->img_wl, info->sz,
			0);
		mlx_put_image_to_window(info->mlx, info->win, info->img_wl, 2
			* info->sz, 0);
		mlx_string_put(info->mlx, info->win, 10, 15, 0x00ffff, "step: ");
		mlx_string_put(info->mlx, info->win, 80, 15, 0x00ffff,
			ft_itoa_without_mlc(info->steps, str));
	}
	else
	{
		ft_putstr_fd("step: ", 1, 0);
		ft_putnbr_fd(info->steps, 1);
		write(1, "\n", 1);
	}
}
