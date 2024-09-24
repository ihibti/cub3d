/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:24:12 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/24 15:13:56 by gchenot          ###   ########.fr       */
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
	// int			sky;
	// int			wall;
	// int			floor;
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
	char		*file;
	int			fd;
	int			nb_line;
	int			map_start_line;
	int			map_height;
	int			map_width;
	int			inside_map;
	double		parsed;
	int			nb_start;
	void		*mlx_img;
	void		*img_addr;
	int			img_bpp;
	int			img_slen;
	int			img_endian;
	char		*n_path;
	char		*e_path;
	char		*s_path;
	char		*w_path;
	t_color		floor;
	t_color		ceiling;
    int parsed_f;
    int parsed_c;
}				t_ori;

void			truc_move(t_ori *ori);
// char			**allocate_map(void);
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
// void			debugging(t_ori *ori);
int				slide_x(t_ori *ori, t_player *player, double dir_m);
int				slide_y(t_ori *ori, t_player *player, double dir_m);
void			map_dimensions(int *x_max, int *y_max, char **map);


unsigned int create_rgb(int t, int r, int g, int b);
void	draw_ceiling(t_ori *ori, char *img_data, int drawstart, int x, int *y);
void	draw_floor(t_ori *ori, char *img_data, int x, int y);

// Parsing
int				open_textures_no(t_ori *ori);
int				open_textures_so(t_ori *ori);
int				open_textures_ea(t_ori *ori);
int				open_textures_we(t_ori *ori);
void			parsing_colors(t_ori *ori, char *line);
void			parsing_textures(t_ori *ori, char *line);
// void			parse_map(t_ori *ori, char *line, int j); //static
void			parsing_map(t_ori *ori);
void			parsing(t_ori *ori);
void			create_map(t_ori *ori);
void			open_fd(t_ori *ori);
// void			check_file(t_ori *ori);
void			valid_extension(t_ori *ori, char *str);
int				check_comma(char *line);
int				find_longest_line(char **map);
int				check_valid_start(char **map);
int				check_map_leaks(t_ori *ori, int x, int y);

// Utils
// int				contains_char(char *set, char c);	//static

// Free && Exit
void			free_tab(char **tab);
int				free_player(t_player *player);
int				free_map(char **map);
int				free_textures(t_ori *ori);
// void			free_game(t_ori *ori);
// void			brexit(t_ori *ori, char *error, char *line);
void			cut_xpm(char *str);
int				ft_isspace(char c);
int				jump_space(char *str);

#endif
