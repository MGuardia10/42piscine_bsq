/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:18:35 by mguardia          #+#    #+#             */
/*   Updated: 2024/04/06 10:46:55 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/bsq.h"

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
		write(1, str++, 1);
	if (cont != argc - 1)
		write(1, "\n", 1);
}

int	count_cols(char *file)
{
	int		col;
	int		fd;
	char	buffer;

	col = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		;
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
		col++;
	close(fd);
	return (col);
}
