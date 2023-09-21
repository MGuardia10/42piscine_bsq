/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivero- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:03:52 by jrivero-          #+#    #+#             */
/*   Updated: 2023/06/21 16:35:01 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

char	*stdin_to_file(void);

int	main(int argc, char *argv[])
{
	int		cont;
	int		rows;

	rows = 0;
	if (argc >= 2)
	{
		cont = 0;
		while (++cont < argc)
		{
			if (ft_validate_file(argv[cont], &rows) <= 0)
				ft_putstr(MAP_ERROR, cont, argc);
			else
				ft_find_biggest(argv[cont], rows, cont, argc);
		}
	}
	else if (argc == 1)
	{
		if (stdin_to_file() == NULL)
			return (0);
		if (ft_validate_file("stdin.txt", &rows) <= 0)
			ft_putstr(MAP_ERROR, 0, argc);
		else
			ft_find_biggest("stdin.txt", rows, 0, argc);
	}
	return (0);
}
