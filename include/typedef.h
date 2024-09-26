/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:55:10 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/26 16:27:19 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct s_display
{
	void		*img;
	char		*data;
	int			bpp;
	int			width;
	int			height;
	int			sizeline;
	int			endian;
}				t_display;

typedef struct s_ray
{
	double		dirangle;
	double		pos_ray_x;
	double		pos_ray_y;
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
	double		side_distx;
	double		side_disty;
	double		plane_angle;
	int			map_y;
	int			map_x;
	int			last_hit;
	bool		odd;
	int			color;
	double		camera_x;
	double		wall_stripe;
	int			coord_stripe;
	int			drawstart;
	int			drawend;
	t_display	*wall;
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
	bool		recast;
	int			img_w;
	int			img_h;
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
	char		*n_path;
	char		*e_path;
	char		*s_path;
	char		*w_path;
	int			parsed_f;
	int			parsed_c;
	int			mouse;
	t_color		floor;
	t_color		ceiling;
	t_display	display;
	t_display	textures[4];
}				t_ori;

#endif