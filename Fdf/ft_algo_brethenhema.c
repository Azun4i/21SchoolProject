#include "ft_fdf.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < data->res_x)
	{
		if (y > 0 && y < data->res_y)
		{
			dst = data->addr + (y * data->line_length + x * \
									(data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	ft_algo_brethenhema(t_data *data, t_cor cor_x_y)
{
	float	y_step;
	float	x_step;
	int		max;

	x_step = cor_x_y.x1 - cor_x_y.x;
	y_step = cor_x_y.y1 - cor_x_y.y;
	max = ft_find_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(cor_x_y.x - cor_x_y.x1) || (int)(cor_x_y.y - cor_x_y.y1))
	{
		pixel_put(data, (int)cor_x_y.x, (int)cor_x_y.y, data->color);
		cor_x_y.x += x_step;
		cor_x_y.y += y_step;
	}
}
