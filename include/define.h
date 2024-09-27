/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchenot <gchenot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:12:04 by gchenot           #+#    #+#             */
/*   Updated: 2024/09/27 12:17:25 by gchenot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define _USE_MATH_DEFINES

// Libraries
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
# define CAMERA_SPEED 0.05
# define SCREEN_W 1600
# define SCREEN_H 900
# define SCREEN_NAME "cub3D des CHAAAAA(3)D !"
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
# define ERROR_ARGS "Error: check tes arguments -> ./cub3D map.cub!\n"
# define ERROR_OPEN "Error: cannot open file.. \n"
# define ERROR_MAP_ARG "Error: whatchu doin' ? where is your map ?\n"
# define ERROR_MAP_ARGS "Error: chill mann, too many arguments here..\n"
# define ERROR_MAP_LEAKS "Error: map has a holeeee\n"
# define ERROR_CLOSEFD "Error: cannot close fd\n"
# define ERROR_EXTENSION "Error: wagwan '.cub' file ??\n"
# define ERROR_MAP "Error: map invalid\n"
# define ERROR_MAP_SIZE "Error: map size exceeded watchu up 2 ??\n"
# define ERROR_PATH "Error: bro, path(s) already set before\n"
# define ERROR_PARSING "Error: parsee mieux nan ?\n"
# define ERROR_START "Error: Bro are you a ninja ? KAGEBUNSHIN NO JUTSUUUUUU!\n"
# define ERROR_RGB "Error: RGB values shoudl be btw [0, 255], need 3 of 'em !\n"
# define ERROR_FILE "Error: file FD is buggin\n"
# define ERROR_MLX "Error: mlx failed to launch! \n"
# define ERROR_MLXWIN "Error: mlx window failed to launch! \n"
# define ERROR_MLXIMG "Error: mlx image failed to launch ! \n"
# define ERROR_MLXDATA "Error: mlx data failed to launch ! \n"
# define ERROR_XPM "Error: mlx failed to load xpm image\n"
# define ERROR_INITP "Error: init player failed\n"
# define ERROR_INITR "Error: init ray failed\n"
# define ERROR_DUP "Error: dup'inn not on point..\n"
# define ERROR_UTEXTURE "Error: unknown texture\n"
# define ERROR_TEXTUREPATH "Error: where is da path man\n"
# define ERROR_NTEXTURE "Error: North texture path is missing\n"
# define ERROR_STEXTURE "Error: South texture path is missing\n"
# define ERROR_ETEXTURE "Error: East texture path is missing\n"
# define ERROR_WTEXTURE "Error: West texture path is missing\n"
# define ERROR_CEILINGDUP "Error: ceiling already set man\n"
# define ERROR_FLOORDUP "Error: floor is lava\n"
# define ERROR_SPAWN "Error: why you even tryna spawn more than once ?\n"
# define ERROR_NOMAP "Error: how can you even play with no map ?\n"
# define ERROR_VALUE "Error: don't even try, we check the values\n"

#endif