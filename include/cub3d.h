/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:24:12 by ihibti            #+#    #+#             */
/*   Updated: 2024/08/28 11:29:11 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _USE_MATH_DEFINES
# include "mlx.h"
# include "stdio.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define SCREEN_W 1500
# define SCREEN_H 700
# define UP 222
# define LEFT_V 223
# define RIGHT_V 224
# define DOWN 225
# define FORWARD 226
# define BACKWARDS 227
# define RIGHT_M 228
# define LEFT_M 229
# define delta 0.1
# define FOV (M_PI / 4)
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define VIOLET 0x00FF00FF
# define YELLOW 0x00FFFF00
# define GREEN 0x0000FF00
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define ORANGE 0x00FFA500
# define PINK 0x00FFC0CB
# define BROWN 0x00A52A2A
# define GRAY 0x00808080
# define LIGHT_GRAY 0x00D3D3D3
# define DARK_GRAY 0x00A9A9A9

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		orientation_x;
	double		orientation_y;
	int			x_map;
	int			y_map;
	float		dir_angle;
	int			hit;
	int			step;
	double		delt_distx;
	double		delt_disty;
	double		perpwalldist;

}				t_player;

typedef struct s_ori
{
	t_player	*player;
	char		**map;
	void		*mlxptr;
	void		*mlxwin;
	int			sky;
	int			wall;
	int			floor;
}				t_ori;

char			**allocate_map(void);
void			free_map(char **map);
int				init_player(t_ori *ori);
int				init(t_ori *ori);
int				init_x_pl(t_ori *ori);
int				init_y_pl(t_ori *ori);
void			init_dirangle(t_ori *ori);
int				check_init_p(t_ori *ori);
int				start_mlx(t_ori *ori);
int				brexit(t_ori *ori);
int				han_inp(int key, t_ori *ori);

#endif