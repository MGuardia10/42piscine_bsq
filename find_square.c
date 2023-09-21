/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:19:24 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/21 17:23:44 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	find_max_value(int **num_matrix, int rows, int cols, int *params)
{
	int	i;
	int	j;

	params[0] = 0;
	params[1] = 0;
	params[2] = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (num_matrix[i][j] > params[0])
			{
				params[0] = num_matrix[i][j];
				params[1] = j;
				params[2] = i;
			}
			j++;
		}
		i++;
	}
}

void	change_square(char **init_matrix, char fill, int *params)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = params[2] - params[0];
	j = params[1] - params[0];
	x = params[2];
	while (x > i)
	{
		y = params[1];
		while (y > j)
		{
			init_matrix[x][y] = fill;
			y--;
		}
		x--;
	}
}

void	print_result(char **init_matrix, int *params, char *file)
{
	int		len;
	char	*rules;
	char	fill;

	len = file_len(file);
	rules = file_to_str(file, len);
	fill = rules[len - 1];
	change_square(init_matrix, fill, params);
}

void	print_final_matrix(char **matrix, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_find_biggest(char *file, int rows, int cont, int argc)
{
	int		cols;
	char	**init_matrix;
	int		**bin_matrix;
	int		**num_matrix;
	int		params[3];

	cols = count_cols(file);
	init_matrix = initial_matrix(rows, cols, file);
	bin_matrix = binary_matrix(init_matrix, rows, file);
	num_matrix = numeric_matrix(bin_matrix, rows, cols);
	find_max_value(num_matrix, rows, cols, params);
	print_result(init_matrix, params, file);
	print_final_matrix(init_matrix, rows, cols);
	if (cont != argc - 1)
		write(1, "\n", 1);
	free_char_matrix(init_matrix, rows);
	free_int_matrix(bin_matrix, rows);
	free_int_matrix(num_matrix, rows);
}
