#include "ft_fdf.h"

void	ft_new_struct(t_data *data)
{
	data->quan_line = 0;
	data->height = 0;
	data->width = 0;
	data->matrix_z = NULL;
	data->zoom = 10;
	data->color = 0;
	data->moving_x = 0;
	data->moving_y = 0;
	data->flag = 0;
	data->cor_z = 0;
	data->ch_x = 0.0;
	data->ch_y = 0.0;
	data->ch_z = 0.0;
	data->co_z = 0.0;
	data->res_x = 1920;
	data->res_y = 1080;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
}

int	ft_count_words(char const *t, char c)
{
	int	i;
	int	count_w;

	i = 0;
	count_w = 0;
	while (t[i])
	{
		while (t[i] == c)
			i++;
		if (t[i])
			count_w++;
		while (t[i] != c && t[i])
			i++;
	}
	return (count_w);
}

void	ft_free_matrix(t_data *data, int **mas)
{
	int		lines;
	int		linesnumber;

	lines = 0;
	linesnumber = data->height;
	while (lines < linesnumber)
	{
		free(mas[lines]);
		lines++;
	}
	free(mas);
}

int	ft_find_max(int a, int b)
{
	if (a > b)
		return ((int)a);
	else
		return ((int)b);
}

float	ft_mod(float a)
{
	if (a < 0)
		return ((a * -1));
	else if (a > 0)
		return (a);
	else
		return (a);
}
