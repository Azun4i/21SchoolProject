#include "ft_fdf.h"

int	ft_wat_color(int z)
{
	if (z > 0)
		return (1);
	return (0);
}

void	ft_move_map_xyz(t_data *data, int key)
{
	if (key == 92)
		data->ch_y += 0.05;
	if (key == 91)
		data->ch_x += 0.05;
	if (key == 88)
		data->ch_y -= 0.05;
	if (key == 87)
		data->ch_x -= 0.05;
}

void	ft_move_map(t_data *data, int key)
{
	if (key == 126)
		data->moving_y -= 10;
	if (key == 125)
		data->moving_y += 10;
	if (key == 123)
		data->moving_x -= 10;
	if (key == 124)
		data->moving_x += 10;
}

void	ft_new_crdnts(t_cor *cor)
{
	cor->x = 0;
	cor->y = 0;
	cor->x1 = 0;
	cor->y1 = 0;
}
