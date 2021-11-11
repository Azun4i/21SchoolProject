#ifndef FT_FDF_H
# define FT_FDF_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>

typedef struct s_data
{
	int		height;
	int		width;
	int		**matrix_z;
	int		quan_line;
	int		zoom;
	int		color;
	int		moving_x;
	int		moving_y;
	int		flag;
	int		cor_z;
	float	ch_x;
	float	ch_y;
	float	ch_z;
	float	co_z;
	int		res_x;
	int		res_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*mlx_ptr;
	void	*win_ptr;
}t_data;

typedef struct s_crdnts
{
	float	x;
	float	y;
	float	x1;
	float	y1;

}t_cor;

void	ft_read_file_and_fill_matrix(char *filename, t_data *data);
void	ft_get_hight_width(int fd, t_data *data);
void	ft_creat_matrix(t_data *data);
void	ft_fill_matrix(t_data *data, char *filename);
void	ft_algo_brethenhema(t_data *data, t_cor cor_x_y);
void	ft_rotete_x(float *x, float z, float alfa, t_data *data);
void	ft_rotete_y(float *y, float z, float alfa, t_data *data);
void	ft_rotete_z(float *x, float *y, float alfa);

void	ft_do_algo_brethenhema(t_data *data, t_cor *cor_x_y);
void	ft_izo_paint(float *x, float *y, int z, t_data *data);
int		ft_key_catch(int key, t_data *data, t_cor cor_x, t_cor cor_y);
void	ft_paint(t_data *data, t_cor cor_x, t_cor cor_y);

void	*ft_free_int(int *str);
void	ft_new_struct(t_data *data);
int		ft_count_words(char const *t, char c);
void	ft_free_matrix(t_data *data, int **mas);
int		ft_find_max(int a, int b);
float	ft_mod(float a);
int		ft_wat_color(int z);
void	ft_new_crdnts(t_cor *cor);
void	ft_move_map(t_data *data, int key);
void	ft_move_map_xyz(t_data *data, int key);
#endif