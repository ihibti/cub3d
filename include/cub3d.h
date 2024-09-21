/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:24:12 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/20 10:54:15 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _USE_MATH_DEFINES

# include "define.h"

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

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

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
	char 		*file;
	int 		fd;
	int 		nb_line;
	int 		map_start_line;
	int 		map_height;
	int 		map_width;
	t_color		floor_rgb;
	t_color		ceiling_rgb;
}				t_ori;

void			truc_move(t_ori *ori);
char			**allocate_map(void);
// void			free_map(char **map);
int				init_player(t_ori *ori);
int				init(t_ori *ori, char *file);
int				init_pl(t_ori *ori);
void			init_dirangle(t_ori *ori);
int				check_init_p(t_ori *ori);
int				start_mlx(t_ori *ori, char *file);
int				brexit(t_ori *ori);
int				han_inp_press(int key, t_ori *ori);
int				han_inp_release(int key, t_ori *ori);
int				raycasting(t_ori *ori);
void			dda_alg(t_ori *ori, t_ray *ray, int x);
// void			debugging(t_ori *ori);
int				slide_x(t_ori *ori, t_player *player, double dir_m);
int				slide_y(t_ori *ori, t_player *player, double dir_m);
void			map_dimensions(int *x_max, int *y_max, char **map);

// Parsing
// void			parsing_colors(t_ori *ori, char *line);
// void			parsing_textures(t_ori *ori, char *line);
// void			parse_map(t_ori *ori, char *line, int j);
// void			parsing_map(t_ori *ori);
// void			parsing(t_ori *ori);
void			create_map(t_ori *ori);
void			open_fd(t_ori *ori);
// void			check_file(t_ori *ori);
// // void			valid_extension(char *str);
// int				check_comma(char *line);
// int				find_longest_line(char **map);
// int				check_valid_start(char **map);
// int	check_map_leaks(t_ori *ori, int x, int y);
// void	parse_line(t_ori *ori, char *line, int i);

// Utils
// int				contains_char(char *set, char c);

// Free && Exit
void			free_tab(char **tab);
int				free_player(t_player *player);
int				free_map(char **map);
int				free_textures(t_ori *ori);
// void			free_game(t_ori *ori);
// void			brexit(t_ori *ori, char *error, char *line);

#endif