/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:25 by mguardia          #+#    #+#             */
/*   Updated: 2023/06/21 17:24:08 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLIB_H
# define FTLIB_H
# define MAP_ERROR "map error\n"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str, int cont, int argc);
int		ft_print_error(void);
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
