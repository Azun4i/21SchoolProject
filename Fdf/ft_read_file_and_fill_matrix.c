#include "ft_fdf.h"

void	ft_read_file_and_fill_matrix(char *filename, t_data *data)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0 || (read(fd, buf, 0) < 0))
		exit(1);
	ft_new_struct(data);
	ft_get_hight_width(fd, data);
	ft_creat_matrix(data);
	close(fd);
	ft_fill_matrix(data, filename);
}

void	ft_fill_matrix(t_data *data, char *filename)
{
	int		j;
	int		k;
	int		fd;
	char	*line;
	char	**mas;

	j = 0;
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		exit(1);
	while (get_next_line(fd, &line))
	{
		mas = ft_split(line, ' ');
		k = -1;
		line = ft_free(line);
		while (mas[++k])
		{
			data->matrix_z[j][k] = ft_atoi(mas[k]);
			free(mas[k]);
		}
		free(mas);
		j++;
	}
	line = ft_free(line);
	close(fd);
}

void	ft_get_hight_width(int fd, t_data *data)
{
	char	*line;

	line = NULL;
	if (fd == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		data->height++;
		data->width = ft_count_words(line, ' ');
		line = ft_free(line);
	}
	line = ft_free(line);
	close(fd);
}

void	ft_creat_matrix(t_data *data)
{
	int	k;

	k = 0;
	data->matrix_z = (int **) malloc(sizeof (int *) * data->height + 1);
	if (data->matrix_z == NULL)
		exit(1);
	while (k <= data->height)
	{
		data->matrix_z[k] = (int *) malloc(sizeof(int) * data->width + 1);
		if (data->matrix_z[k] == NULL)
		{
			ft_free_matrix(data, data->matrix_z);
			exit(1);
		}
		k++;
	}
	data->matrix_z[k] = NULL;
}
