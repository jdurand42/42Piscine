/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 10:06:01 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 22:58:10 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_map(t_params *params, char *tmp_map)
{
	int i;
	int j;

	i = ft_skipt_first_line(tmp_map);
	if (!ft_check_map2(params, tmp_map))
		return (0);
	j = i + 1;
	j = ft_skipt_first_line_j(tmp_map, j);
	params->width = j - i - 1;
	j = i + 1;
	i = 0;
	while (tmp_map[j])
	{
		i++;
		if (tmp_map[j] == '\n')
		{
			if ((i - 1) != params->width)
				return (0);
			i = 0;
		}
		if (!(ft_check_same(params, tmp_map[j])))
			return (0);
		j++;
	}
	return (1);
}

int		ft_check_same(t_params *params, char tmp_map)
{
	if (tmp_map != params->empty && tmp_map != params->obstacle &&
		tmp_map != params->full && tmp_map != '\n')
		return (0);
	else
		return (1);
}

int		ft_skipt_first_line(char *tmp_map)
{
	int i;

	i = 0;
	while (tmp_map[i] != '\n')
		i++;
	return (i);
}

int		ft_check_map2(t_params *params, char *tmp_map)
{
	int i;
	int lines;

	i = ft_skipt_first_line(tmp_map);
	lines = 0;
	while (tmp_map[i])
	{
		if (tmp_map[i] == '\n')
			lines++;
		i++;
	}
	if (lines - 1 != params->height)
		return (0);
	i = ft_skipt_first_line(tmp_map);
	while (tmp_map[i])
	{
		if (tmp_map[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_skipt_first_line_j(char *tmp_map, int i)
{
	while (tmp_map[i] != '\n')
		i++;
	return (i);
}
