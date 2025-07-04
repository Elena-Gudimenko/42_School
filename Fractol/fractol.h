/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:38:49 by elvictor          #+#    #+#             */
/*   Updated: 2025/05/08 21:39:21 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH	800
# define HEIGHT	800

# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

# define MAGENTA_BURST	0xFF00FF
# define LIME_SHOCK		0xCCFF00
# define NEON_ORANGE		0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM		0x33CCCC
# define HOT_PINK		0xFF66B2
# define ELECTRIC_BLUE	0x0066FF
# define LAVA_RED		0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixels;
	int		line_len;
	int		endian;
}				t_img;
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		max_iteration;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}				t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
double		map(int pixel, double min, double max, int size);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);

#endif