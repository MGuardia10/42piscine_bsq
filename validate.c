/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:55:31 by jrivero-          #+#    #+#             */
/*   Updated: 2023/06/20 12:46:29 by jrivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	valid_fl(char *str, int len)
{
	int	total;
	int	i;

	total = 0;
	if (len >= 4)
	{
		i = 0;
		while (len - i > 3)
		{
			if (str[i] < '0' || str[i] > '9')
				return (-1);
			total *= 10;
			total += str[i] - '0';
			i++;
		}
		if (!(str[i] != str[i + 1] && str[i] != str[i + 2]
				&& str[i + 2] != str[i + 1]) && str[i] != ' ')
			return (-1);
	}
	return (total);
}		

char	*first_lane(char *file, int *fd, int *len)
{
	unsigned char	c;
	char			*str;
	int				i;

	while (read(*fd, &c, 1) == 1 && (*len)++ != -1)
		if (c == '\n')
			close(*fd);
	str = (char *) malloc (*(len) * sizeof(char));
	*fd = open(file, O_RDONLY);
	i = 0;
	while (i < *len - 1)
	{
		read(*fd, &c, 1);
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	*len = valid_fl(str, *len - 1);
	if (*len <= 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	other_lanes(int fd, int len, char *s, int i)
{
	char	c;
	int		col;
	int		ant;
	int		slen;

	slen = ft_strlen(s);
	while (read(fd, &c, 1) == 1 && c != '\n')
		col = 0;
	while (read(fd, &c, 1) == 1)
	{
		if (i >= len || ((c != s[slen - 2]
					&& c != s[slen - 3]) && c != '\n'))
			return (-1);
		if (c == '\n')
		{
			if (i == 0)
				ant = col;
			else if (ant != col)
				return (-1);
			col = -1;
			i++;
		}
		col++;
	}
	return (i == len);
}

int	ft_validate_file(char *file, int *rows)
{
	int		aux;
	int		len;
	int		fd;
	char	*str;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_print_error());
	str = first_lane(file, &fd, &len);
	if (str == NULL)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	aux = other_lanes(fd, len, str, 0);
	free(str);
	*rows = len;
	return (aux);
}
