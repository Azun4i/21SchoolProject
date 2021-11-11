#include "ft_fdf.h"

void	ft_rotete_x(float *y, float z, float alfa, t_data *data)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alfa) + z * data->co_z * sin(alfa);
	z = -prev_y * sin(alfa) + z * cos(alfa);
}

void	ft_rotete_y(float *x, float z, float alfa, t_data *data)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(alfa) + z * data->co_z * sin(alfa);
	z = -prev_x * sin(alfa) + z * cos(alfa);
}

void	ft_rotete_z(float *x, float *y, float alfa)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(alfa) - prev_y * sin(alfa);
	*y = -prev_x * sin(alfa) + prev_y * cos(alfa);
}

void	ft_izo_paint(float *x, float *y, int z, t_data *data)
{
	float	prev_x;
	float	prev_y;

	(void )data;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599) + z;
	*y = (prev_x + prev_y) * sin(0.523599) - z;
}
