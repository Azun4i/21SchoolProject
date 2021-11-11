#include "ft_fdf.h"

void	ft_do_zoom(t_data *data, t_cor *cor_x_y)
{
	cor_x_y->x *= data->zoom;
	cor_x_y->x1 *= data->zoom;
	cor_x_y->y *= data->zoom;
	cor_x_y->y1 *= data->zoom;
}

void	ft_do_mooving(t_data *data, t_cor *cor_x_y)
{
	cor_x_y->x += data->moving_x;
	cor_x_y->x1 += data->moving_x;
	cor_x_y->y += data->moving_y;
	cor_x_y->y1 += data->moving_y;
}

void	ft_do_algo_brethenhema(t_data *data, t_cor *cor_x_y)
{
	int	z;
	int	z1;

	z = data->matrix_z[(int)cor_x_y->y][(int)cor_x_y->x];
	z1 = data->matrix_z[(int)cor_x_y->y1][(int)cor_x_y->x1];
	ft_do_zoom(data, cor_x_y);
	if (ft_wat_color(z) == 1 || ft_wat_color(z1) == 1)
		data->color = 0x008A2BE2;
	else
		data->color = 0x00FF1493;
	if (data->flag == 0)
	{
		ft_izo_paint(&cor_x_y->x, &cor_x_y->y, z, data);
		ft_izo_paint(&cor_x_y->x1, &cor_x_y->y1, z1, data);
	}
	ft_rotete_z(&cor_x_y->x, &cor_x_y->y, (float) data->ch_z);
	ft_rotete_z(&cor_x_y->x1, &cor_x_y->y1, (float) data->ch_z);
	ft_rotete_y(&cor_x_y->x, (float ) z, (float) data->ch_y, data);
	ft_rotete_y(&cor_x_y->x1, (float ) z1, (float) data->ch_y, data);
	ft_rotete_x(&cor_x_y->y, (float) z, (float) data->ch_x, data);
	ft_rotete_x(&cor_x_y->y1, (float) z1, (float) data->ch_x, data);
	ft_do_mooving(data, cor_x_y);
	ft_algo_brethenhema(data, *cor_x_y);
}
