/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:55 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/21 17:27:40 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	free_char_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < (rows + 1))
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_int_matrix(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < (rows + 1))
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
