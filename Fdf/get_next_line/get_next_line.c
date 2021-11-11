#include "get_next_line.h"

static int	find_n(char *str)
{
	int	count;

	count = -1;
	while (str[++count] != '\0')
		if (str[count] == '\n')
			return (count);
	return (-1);
}

static int	chek_prm(int fd, char **buf)
{
	*buf = NULL;
	if (BUFFER_SIZE <= 0 || (read(fd, buf, 0) < 0))
		return (1);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (1);
	return (0);
}

static int	chek_re(char **line, char **re, char **buf)
{
	int		pos_n;

	pos_n = find_n(*re);
	if (pos_n >= 0)
	{
		*line = ft_free(*line);
		(*re)[pos_n] = '\0';
		*line = ft_strdup(*re);
		*re = ft_strcpy(*re, *re + pos_n + 1);
		*buf = ft_free(*buf);
		return (1);
	}
	else
	{
		*line = ft_free(*line);
		*line = ft_strdup(*re);
		*re = ft_free(*re);
	}
	*re = ft_free(*re);
	return (0);
}

int	chek_buf(char **line, char **buf, char **re)
{
	int				pos_n;
	char			*tmp;

	pos_n = find_n(*buf);
	if (pos_n >= 0)
	{
		(*buf)[pos_n] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, *buf);
		tmp = ft_free(tmp);
		tmp = *re;
		*re = ft_strdup(*buf + pos_n + 1);
		tmp = ft_free(tmp);
		*buf = ft_free(*buf);
		return (1);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, *buf);
		tmp = ft_free(tmp);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int				rb;
	char			*buf;
	static char		*re = NULL;

	rb = 1;
	if ((chek_prm(fd, &buf)) == 1)
		return (-1);
	*line = ft_strdup("");
	if (re == NULL)
		re = ft_strdup("");
	else if (chek_re(line, &re, &buf) == 1)
		return (1);
	while (rb > 0)
	{
		rb = read(fd, buf, BUFFER_SIZE);
		buf[rb] = '\0';
		if ((chek_buf(line, &buf, &re)) == 1)
		{
			buf = ft_free(buf);
			return (1);
		}
	}
	buf = ft_free(buf);
	re = ft_free(re);
	return (0);
}
