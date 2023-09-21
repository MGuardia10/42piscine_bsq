/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:59:38 by jrivero-          #+#    #+#             */
/*   Updated: 2023/06/21 14:32:32 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int	valid_fl(char *str, int len);

int	file_len(char *file)
{
	int		len;
	int		fd;
	char	a;

	len = 0;
	fd = open (file, O_RDONLY);
	while (read(fd, &a, 1) == 1 && a != '\n')
		len++;
	close(fd);
	return (len);
}

char	*file_to_str(char *file, int len)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	str = (char *) malloc ((len + 1) * sizeof(char));
	fd = open(file, O_RDONLY);
	while (i < len)
	{
		read(fd, &str[i], 1);
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}	

int	first_stdin(char *file, int *fd)
{
	char	*str;
	int		len;
	int		total;

	total = 0;
	close(*fd);
	len = file_len(file);
	if (len < 4)
		return (-1);
	str = file_to_str(file, len);
	total = valid_fl(str, len);
	return (total);
}

char	*stdin_to_file(void)
{
	int		aux;
	int		i;
	int		fd;
	char	a;
	int		fd2;

	fd = open("stdin.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	i = 0;
	aux = 2;
	while (i <= aux && read(0, &a, 1) == 1)
	{
		if (i == 0 && a == '\n')
		{
			i++;
			aux = first_stdin("tmp.txt", &fd2);
		}
		else if (i != 0 && a == '\n')
			i++;
		write(fd, &a, 1);
		write(fd2, &a, 1);
	}
	if (aux == -1)
		return (NULL);
	return ("stdin.txt");
}
