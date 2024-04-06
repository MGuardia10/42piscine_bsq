/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:16:24 by mguardia          #+#    #+#             */
/*   Updated: 2024/04/06 10:50:43 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bsq.h"

void	create_bin_matrix(int **b_matrix, char **i_matrix, int rows, char *file)
{
	int		len;
	int		cols;
	int		i;
	int		j;
	char	*rules;

	i = 0;
	j = 0;
	len = file_len(file);
	cols = count_cols(file);
	rules = file_to_str(file, len);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i_matrix[i][j] == rules[len - 2])
				b_matrix[i][j] = 0;
			else if (i_matrix[i][j] == rules[len - 3])
				b_matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}

int	**binary_matrix(char **i_matrix, int rows, char *file)
{
	int	cols;
	int	**b_matrix;
	int	i;

	cols = count_cols(file);
	b_matrix = (int **) malloc((rows + 1) * sizeof(int *));
	if (!b_matrix)
		exit(EXIT_FAILURE);
	i = -1;
	while (i++ < rows)
	{
		b_matrix[i] = (int *) malloc((cols + 1) * sizeof(int));
		if (!b_matrix[i])
			(free_int_matrix(b_matrix, rows), exit(EXIT_FAILURE));
	}
	b_matrix[i] = NULL;
	create_bin_matrix(b_matrix, i_matrix, rows, file);
	return (b_matrix);
}
