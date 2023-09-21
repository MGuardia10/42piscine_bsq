/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:59:01 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/21 11:59:30 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	min(int up, int left, int diag)
{
	int	min;

	min = up;
	if (min > left)
		min = left;
	if (min > diag)
		min = diag;
	return (min);
}

void	create_num_matrix(int **n, int **b, int rows, int cols)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = -1;
	y = -1;
	i = 1;
	while (++x < rows)
		n[x][0] = b[x][0];
	while (++y < cols)
		n[0][y] = b[0][y];
	while (i < rows)
	{
		j = 1;
		while (j < cols)
		{
			if (b[i][j] == 1)
				n[i][j] = min(n[i][j - 1], n[i - 1][j], n[i - 1][j - 1]) + 1;
			else
				n[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**numeric_matrix(int **b_matrix, int rows, int cols)
{
	int	**n_matrix;
	int	i;

	i = -1;
	n_matrix = (int **) malloc ((rows + 1) * sizeof(int *));
	while (i++ < rows)
		n_matrix[i] = (int *) malloc ((cols + 1) * sizeof(int));
	n_matrix[i] = NULL;
	create_num_matrix(n_matrix, b_matrix, rows, cols);
	return (n_matrix);
}
