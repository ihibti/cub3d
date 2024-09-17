/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:24:12 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/17 20:52:13 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _USE_MATH_DEFINES
# include "mlx.h"
# include "stdio.h"

#ifdef __APPLE__
    #define KEY_ESCAPE 53 // macOS keycode for Escape
    #define KEY_W 13      // macOS keycode for 'W'
    #define KEY_S 1       // macOS keycode for 'S'
    #define KEY_D 2       // macOS keycode for 'D'
    #define KEY_A 0       // macOS keycode for 'A'
    #define KEY_LEFT 123  // macOS keycode for Left Arrow
    #define KEY_RIGHT 124 // macOS keycode for Right Arrow
#else
    #include <X11/keysym.h>
    #define KEY_ESCAPE XK_Escape
    #define KEY_W XK_w
    #define KEY_S XK_s
    #define KEY_D XK_d
    #define KEY_A XK_a
    #define KEY_LEFT XK_Left
    #define KEY_RIGHT XK_Right
#endif
# ifdef __APPLE__ // To define XK_d, XK_a, XK_Left, etc.
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
# else
#  include <X11/X.h>
#  include <X11/keysym.h>
# endif

# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define MOVE_SPEED 0.01
# define CAMERA_SPEED 0.02
# define SCREEN_W 1200
# define SCREEN_H 500
# define PIXEL (M_PI) / (SCREEN_H)
# define UP 222
# define LEFT_V 223
# define RIGHT_V 224
# define DOWN 225
# define FORWARD 226
# define BACKWARDS 227
# define RIGHT_M 228
# define LEFT_M 229
# define delta 0.1
# define FOV 0.66
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

typedef struct s_ray
{
	double		dirangle;
	double		pos_rayX;
	double		pos_rayY;
	double		dir_ray_x;
	double		dir_ray_y;
	double		perp_dist;
	double		plane_dirx;
	double		plane_diry;
	double		plane_posx;
	double		plane_posy;
	int			hit;
	int			stepx;
	int			stepy;
	double		delta_x;
	double		delta_y;
	double		sideDistX;
	double		sideDistY;
	double		plane_angle;
	int			mapY;
	int			mapX;
	int			last_hit;
	bool		odd;
	int			color;
	double		cameraX;
	double		wall_stripe;
	int			coord_stripe;
}				t_ray;
typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			x_map;
	int			y_map;
	double		dir_angle;
	t_ray		*ray;

}				t_player;

typedef struct s_display
{
	void		*img;
	char		*data;
	int			bpp;
	int			width;
	int			height;
}				t_display;

typedef struct s_ori
{
	t_player	*player;
	char		**map;
	void		*mlxptr;
	void		*mlxwin;
	int			sky;
	int			wall;
	int			floor;
	bool		recast;
	int			img_w;
	int			img_h;
	t_display	display;
	t_display	textures[4];
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
}				t_ori;

void			truc_move(t_ori *ori);
char			**allocate_map(void);
void			free_map(char **map);
int				init_player(t_ori *ori);
int				init(t_ori *ori);
int				init_pl(t_ori *ori);
void			init_dirangle(t_ori *ori);
int				check_init_p(t_ori *ori);
int				start_mlx(t_ori *ori);
int				brexit(t_ori *ori);
int				han_inp_press(int key, t_ori *ori);
int				han_inp_release(int key, t_ori *ori);
int				raycasting(t_ori *ori);
void			dda_alg(t_ori *ori, t_ray *ray, int x);
void			debugging(t_ori *ori);
int				slide_x(t_ori *ori, t_player *player, double dir_m);
int				slide_y(t_ori *ori, t_player *player, double dir_m);
void			map_dimensions(int *x_max, int *y_max, char **map);

#endif