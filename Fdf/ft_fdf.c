#include "ft_fdf.h"

void	ft_do_add_x(float x, float y, t_cor *cor)
{
	cor->x = x;
	cor->x1 = x + 1;
	cor->y = y;
	cor->y1 = y;
}

void	ft_do_add_y(float x, float y, t_cor *cor)
{
	cor->x = x;
	cor->x1 = x;
	cor->y = y;
	cor->y1 = y + 1;
}

void	ft_paint(t_data *data, t_cor cor_x, t_cor cor_y)
{
	int	x;
	int	y;

	data->img = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				ft_do_add_x((float )x, (float )y, &cor_x);
				ft_do_algo_brethenhema(data, &cor_x);
			}
			if (y < data->height - 1)
			{
				ft_do_add_y((float )x, (float )y, &cor_y);
				ft_do_algo_brethenhema(data, &cor_y);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

int	ft_key_catch(int key, t_data *data, t_cor cor_x, t_cor cor_y)
{
	if (key == 53)
		exit(0);
	if (key == 92 || key == 91 || key == 88 || key == 87)
		ft_move_map_xyz(data, key);
	if (key == 83)
		data->co_z += 0.05;
	if (key == 84)
		data->co_z -= 0.05;
	if (key == 40)
		data->flag = 1;
	if (key == 37)
		data->flag = 0;
	if (key == 69)
		data->zoom += 2;
	if (key == 78 && data->zoom > 2)
		data->zoom -= 2;
	if (key == 126 || key == 125 || key == 123 || key == 124)
		ft_move_map(data, key);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_paint(data, cor_x, cor_y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_cor	cor_x;
	t_cor	cor_y;

	if (argc > 2)
		exit(1);
	data = (t_data *) malloc(sizeof (t_data));
	if (data == NULL)
		exit(1);
	ft_new_crdnts(&cor_x);
	ft_new_crdnts(&cor_y);
	ft_read_file_and_fill_matrix(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->res_x, data->res_y,
			"windows");
	data->moving_x = data->res_x / 2;
	data->moving_y = data->res_y / 2;
	ft_paint(data, cor_x, cor_y);
	mlx_hook(data->win_ptr, 2, 0, ft_key_catch, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
