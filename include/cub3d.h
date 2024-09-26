/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:24:12 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/26 13:14:56 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "typedef.h"

// MLX
int				start_mlx(t_ori *ori);

// INIT
int				init(t_ori *ori);
int				init_pl(t_ori *ori);
void			init_dirangle(t_ori *ori);
void			init_textures_paths(t_ori *ori);
int				check_init_p(t_ori *ori);

// CONTROL MOVEMENT
void			truc_move(t_ori *ori);
int				slide(t_ori *ori, t_player *player, double dir_m);
int				slide_x(t_ori *ori, t_player *player, double dir_m,double new_y);
int				slide_y(t_ori *ori, t_player *player, double dir_m,double new_x);
int				corner_slide(t_ori *ori, t_player *player, double dir_m);
void			look_left(t_ori *ori);
void			look_right(t_ori *ori);
int				land_secu(t_ori *ori, t_player *player);
int				secu(t_ori *ori, t_player *player, double dir_m);

// HOOKS
int				han_inp_press(int key, t_ori *ori);
int				han_inp_release(int key, t_ori *ori);
int				han_mouse_move(int x, int y, void *param);
// PARSING
void			parsing_colors(t_ori *ori, char *line);
void			parsing_textures(t_ori *ori, char *line);
void			parsing_map(t_ori *ori);
void			parsing(t_ori *ori);
void			create_map(t_ori *ori);
int				check_map_leaks(t_ori *ori, int x, int y);
void			final_map(t_ori *ori);

// PARSING UTILS
void			open_fd(t_ori *ori);
void			valid_extension(t_ori *ori, char *str);
int				check_comma(char *line);
int				find_longest_line(char **map);
int				check_valid_start(char **map);
void	printf_map(char **map); // a delete later

// RAYCASTING
int				raycasting(t_ori *ori);
void			dda_alg(t_ori *ori, t_ray *ray, int x);

// MINIMAP
void			draw_minimap(t_ori *ori);
void			init_mnmap(int *i, int *j, t_ori *ori);
int				is_pov(int x, int y, t_ori *ori);
int				unsafe(int x, int y, char **map);
uint32_t		get_color_mini(int x, int y, char **map, t_ori *ori);

// TEXTURES
unsigned int	create_rgb(int t, int r, int g, int b);
void			draw_ceiling(t_ori *ori, char *img_data, int x, int *y);
void			draw_floor(t_ori *ori, char *img_data, int x, int y);
int				open_textures_no(t_ori *ori);
int				open_textures_so(t_ori *ori);
int				open_textures_ea(t_ori *ori);
int				open_textures_we(t_ori *ori);

// Utils
int				contains_char(char *set, char c);
void			cut_xpm(char *str);
int				ft_isspace(char c);
int				jump_space(char *str);
void			map_dimensions(int *x_max, int *y_max, char **map);
// void			debugging(t_ori *ori);

// Free && Exit
void			free_tab(char **tab);
int				free_player(t_player *player);
int				free_map(char **map);
int				free_textures(t_ori *ori);
// void			free_game(t_ori *ori);
// void			brexit(t_ori *ori, char *error, char *line);
int				brexit(t_ori *ori);

#endif
