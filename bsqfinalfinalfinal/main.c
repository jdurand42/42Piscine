/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:35:41 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 22:58:46 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int g_is_print = 0;

int		main(int argc, char **argv)
{
	int			i;
	char		*tmp_map;
	int			**map;
	t_params	p;
	t_coord		b;

	tmp_map = NULL;
	map = NULL;
	if (argc == 1)
		if ((tmp_map = ft_create_stdin(tmp_map, &p)) != NULL)
			if ((map = ft_create_map(tmp_map, &p, map)) != NULL)
				ft_display(ft_solve(p.width, p.height, &b, map), &p, &b);
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if ((tmp_map = ft_create_files(argv[i], tmp_map, &p)) != NULL)
				if ((map = ft_create_map(tmp_map, &p, map)) != NULL)
					ft_display(ft_solve(p.width, p.height, &b, map), &p, &b);
			i++;
		}
	}
	return (0);
}

char	*ft_create_files(char *file_name, char *tmp_map, t_params *params)
{
	ft_write_nl();
	if ((tmp_map = ft_create_tmp(file_name, tmp_map)) == NULL)
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	else
	{
		if (!ft_init_params(params, tmp_map) || !ft_check_map(params, tmp_map))
		{
			write(2, "map error\n", 10);
			return (NULL);
		}
	}
	return (tmp_map);
}

char	*ft_create_stdin(char *tmp_map, t_params *params)
{
	if ((tmp_map = ft_create_tmp_stdin(tmp_map)) == NULL)
	{
		write(2, "map error\n", 10);
		return (NULL);
	}
	else
	{
		if (!ft_init_params(params, tmp_map) || !ft_check_map(params, tmp_map))
		{
			write(2, "map error\n", 10);
			return (NULL);
		}
	}
	return (tmp_map);
}

void	ft_display(int **map, t_params *params, t_coord *b)
{
	int i;
	int j;

	i = 0;
	while (i < params->height)
	{
		j = 0;
		while (j < params->width)
		{
			if (((j >= (b->x - (b->value - 1))) && (j <= b->x)) &&
				((i >= (b->y - (b->value - 1))) && (i <= b->y)))
				write(1, &params->full, 1);
			else if (map[i][j] == -1)
				write(1, &params->obstacle, 1);
			else
				write(1, &params->empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_write_nl(void)
{
	if (g_is_print == 1)
		write(1, "\n", 1);
	if (g_is_print == 0)
		g_is_print = 1;
}
