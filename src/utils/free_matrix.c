/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:13:55 by mguardia          #+#    #+#             */
/*   Updated: 2024/04/06 10:43:49 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bsq.h"

void	free_char_matrix(char **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < (rows + 1))
		free(matrix[i++]);
	free(matrix);
}

void	free_int_matrix(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < (rows + 1))
		free(matrix[i++]);
	free(matrix);
}
