/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:18:35 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/21 16:32:53 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int cont, int argc)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	if (cont != argc - 1)
		write(1, "\n", 1);
}

int	ft_print_error(void)
{
	return (-1);
}

int	count_cols(char *file)
{
	int		col;
	int		fd;
	char	buffer;
	int		aux;

	col = 0;
	aux = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		aux++;
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		col++;
	close(fd);
	return (col);
}
