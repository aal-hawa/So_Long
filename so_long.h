/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:17:20 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/14 18:02:28 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifdef __APPLE__
    #include "mlx_mac/mlx.h"  // For macOS
#else
    #include "mlx_linux/mlx.h"  // For Linux
#endif
//  #include "mlx_mac/mlx.h"  // For macOS?
 
#include <unistd.h>
#include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
#include <stdio.h>

// #include "mlx_mac/mlx_int.h"

 typedef struct  s_enemy
  {
  	void *img_enemy;
  }               t_enemy;

typedef struct s_info
{
    int	is_have_palyer;
    int	is_have_exit;
    int	count_collectible;
    int	is_arround_wall;

    int	x_length_line_map;
    int	y_length_line_map;
    int	is_first_muddle_last;
    int x_win;
    int y_win;
    int size_img;
    
    void * mlx_ptr;
	void * win_ptr;
	void *img_ptr;
	char *data_addr;
	int bits_per_pixel;
	int size_line;
	int endian;
	int x;
	int y;
    int	x_player;
	int	y_player;
	void	*img_player;
	char map[100][100];
	int collc_addr[100][100];
	void *collcs[100];
	int	last_collc;
	void *img_wall;
	void *img_walk;
	void *img_collc;
	void *img_exit;
  char  for_what_flood;
  int   is_can_get;
  int   is_have_error;
  int   steps;
  int   is_exit_as_wall;
  int   is_Bonus;
  int   x_enemy;
  int   y_enemy;
  int   i_enemy;
  int   ofset;
  int   is_plus;
  int   is_for_bonus;
  int   index_string;
  t_enemy enemy[7];
}			t_info;

 

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
  
void	exitmassege(char *error, t_info *info);
void	map_pars_main(t_info *info);
int	keys_hook(int key_code, t_info *info);
void	ft_strcpy(char *dst, const char *src);
void	put_imgs_to_wind(t_info *info);
int	close_win(t_info *info);
int	animited_enemy(t_info *info);

void	ft_putnbr_fd(int n, int fd, t_info *info);

int		ft_strlen(const char *s);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		ft_putstr_fd(char *s, int fd, int is_malloc);

char	*get_next_line(int fd, t_info *info);
size_t	ft_strlen_line(const char *s);
char	*ft_strdup_line(char *str, int eof);
char	*ft_strdup_after_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*free_char(char *this_string);
#endif