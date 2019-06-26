/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:55:40 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 19:56:04 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int		**ft_create_map(char *tmp_map, t_params *params, int **map)
{
	if ((map = ft_map_alloc(params, map)) == NULL)
		return (NULL);
	if ((map = ft_map_init(tmp_map, params, map)) == NULL)
		return (NULL);
	return (map);
}

int		**ft_map_alloc(t_params *params, int **map)
{
	int i;

	if ((map = (int**)malloc(params->height * sizeof(int*))) == NULL)
		return (NULL);
	i = 0;
	while (i < params->height)
	{
		if ((map[i] = (int*)malloc(params->width * sizeof(int))) == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

int		**ft_map_init(char *tmp_map, t_params *params, int **map)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (tmp_map[k] != '\n')
		k++;
	while (i < params->height)
	{
		j = 0;
		while (j < params->width)
		{
			k++;
			if (tmp_map[k] == params->obstacle)
				map[i][j] = -1;
			else
				map[i][j] = 0;
			j++;
		}
		k++;
		i++;
	}
	free(tmp_map);
	return (map);
}
