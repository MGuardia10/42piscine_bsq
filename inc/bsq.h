/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:25 by mguardia          #+#    #+#             */
/*   Updated: 2024/04/06 10:34:00 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MAP_ERROR "map error\n"

char	*stdin_to_file(void);
int		ft_strlen(char *str);
int		valid_fl(char *str, int len);
void	ft_putstr(char *str, int cont, int argc);
int		count_cols(char *file);
int		ft_validate_file(char *str, int *rows);
void	ft_find_biggest(char *str, int rows, int cont, int argc);
int		file_len(char *file);
char	*file_to_str(char *file, int len);
char	**initial_matrix(int rows, int cols, char *file);
int		**binary_matrix(char **i_matrix, int rows, char *file);
int		**numeric_matrix(int **b_matrix, int rows, int cols);
void	free_char_matrix(char **matrix, int rows);
void	free_int_matrix(int **matrix, int rows);

#endif
