/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:38:29 by mguardia          #+#    #+#             */
/*   Updated: 2024/04/06 10:50:36 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bsq.h"

void	create_init_matrix(int fd, char **matrix)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
		;
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

	matrix = (char **) malloc ((rows + 1) * sizeof(char *));
	if (!matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (i++ < rows)
	{
		matrix[i] = (char *) malloc ((cols + 1) * sizeof(char));
		if (!matrix[i])
			(free_char_matrix(matrix, rows), exit(EXIT_FAILURE));
	}
	matrix[i] = NULL;
	fd = open(file, O_RDONLY);
	create_init_matrix(fd, matrix);
	close(fd);
	return (matrix);
}
