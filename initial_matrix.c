/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:38:29 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/21 12:25:30 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	create_init_matrix(int fd, char **matrix)
{
	char	c;
	int		i;
	int		j;
	int		aux;

	i = 0;
	j = 0;
	aux = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		aux++;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			i++;
			j = 0;
		}
		else
		{
			matrix[i][j] = c;
			j++;
		}
	}
}

char	**initial_matrix(int rows, int cols, char *file)
{
	char	**matrix;
	int		i;
	int		fd;

	i = -1;
	matrix = (char **) malloc ((rows + 1) * sizeof(char *));
	while (i++ < rows)
		matrix[i] = (char *) malloc ((cols + 1) * sizeof(char));
	matrix[i] = NULL;
	fd = open(file, O_RDONLY);
	create_init_matrix(fd, matrix);
	close(fd);
	return (matrix);
}
