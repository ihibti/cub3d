/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:12:04 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/24 18:13:38 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define _USE_MATH_DEFINES

//Libraries
# include "../libft/libft.h"
# include "mlx.h"
# include "stdio.h"
# include <X11/X.h>
# include <X11/keysym.h>
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
# define CAMERA_SPEED 0.2
# define SCREEN_W 1200
# define SCREEN_H 500
// # define PIXEL (M_PI) / (SCREEN_H)
# define UP 222
# define LEFT_V 223
# define RIGHT_V 224
# define DOWN 225
# define FORWARD 226
# define BACKWARDS 227
# define RIGHT_M 228
# define LEFT_M 229
# define DELTA 0.1
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

// Error messages
# define ERROR_INIT "Error: init failed\n"
# define ERROR_MALLOC "Error: ca malloc mal freroo hahah\n"
# define ERROR_ARGS "Error: check tes arguments !\n"
# define ERROR_OPEN "Error: cannot open file..\n"
# define ERROR_MAP_ARG "Error: whatchu doin' ? where is your map ?\n"
# define ERROR_MAP_ARGS "Error: chill mann, too many arguments here..\n"
# define ERROR_CLOSEFD "Error: cannot close fd\n"
# define ERROR_EXT "Error: wagwan '.cub' file ??\n"
# define ERROR_MAP "Error: map invalid\n"
# define ERROR_PATH "Error: Path already set before\n"
# define ERROR_PARSING "Error: Parsing is no nooo\n"
# define ERROR_START "Error: You can't just spawn everywhere you want\n"
# define ERROR_RGB "Error: RGB values shoudl be btw [0, 255]\n"
# define ERROR_FILE "Error: File FD is buggin\n"
# define ERROR_MLX "Error: mlx failed to launch! \n"
# define ERROR_MLXWIN "Error: mlx window failed to launch! \n"
# define ERROR_MLXIMG "Error: mlx image failed to launch ! \n"
# define ERROR_XPM "Error: mlx failed to load xpm image\n"
# define ERROR_INITP "Error: init player failed\n"

#endif