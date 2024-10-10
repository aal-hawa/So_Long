/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:17:20 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/10 20:32:46 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifdef __APPLE__
    #include "mlx_mac/mlx.h"  // For macOS
#else
    #include "mlx_linux/mlx.h"  // For Linux
#endif

#include <unistd.h>
#include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
#include <stdio.h>


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
    
	int		i_fds;
	int		i_childs;
	int		i_wait;
	int		fd_file_r;
	int		fd_file_w;
	int		offset;
	int		ac;
	int		str_i;
	char	*env;
	char	*limiter;
	int		i_limiter;
	char	*path_commd;
	char	**envp;
	int		is_for_w;
	int		is_bonus;
	size_t	i_split;
	int		env_null;
	int		is_exit_one;
}			t_info;

void	exitmassege();
void	map_pars_main(t_info *info);
int	keys_hook(int key_code, t_info *info);

size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c, t_info *info);
int			open_file_w(char *name_file);
int			my_pipe(char **str, t_info *info);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			open_file_w_b(char *name_file);
void		env_data(char **envp, char **env);
int			init_files(char **str, t_info *info);
void		error_pipe(int **fd1, int i, t_info *info, char **strs);
void		ft_putstr_fd(char *s, int fd, int is_malloc);
int			finish_parent(int ***fd, pid_t **frs, t_info *info);
void		de_allocate(int ***fd, pid_t **frs, int i);
void		free_split(char **dst, size_t i);
char		*ft_strdup(const char *str);
void		get_path_command(char **strs, t_info *info);
void		allocate_fds(int ***fd, pid_t **frs, int j);


char	*get_next_line(int fd, t_info *info);
size_t	ft_strlen_line(const char *s);
char	*ft_strdup_line(char *str, int eof);
char	*ft_strdup_after_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*free_char(char *this_string);
#endif