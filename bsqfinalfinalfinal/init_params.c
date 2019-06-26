/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 10:06:56 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 22:10:45 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_init_params(t_params *params, char *tmp_map)
{
	int i;

	i = 0;
	params->height = 0;
	if (tmp_map[i] < '0' || tmp_map[i] > '9')
		return (0);
	while (tmp_map[i] >= '0' && tmp_map[i] <= '9')
	{
		params->height = params->height * 10 + (tmp_map[i] - 48);
		i++;
	}
	if (params->height == 0)
		return (0);
	if (tmp_map[i] < 33 || tmp_map[i] > 126 || tmp_map[i + 1] < 33
		|| tmp_map[i + 1] > 126 || tmp_map[i + 2] < 33 || tmp_map[i + 2] > 126)
		return (0);
	params->empty = tmp_map[i];
	params->obstacle = tmp_map[i + 1];
	params->full = tmp_map[i + 2];
	if (!ft_check_params(params))
		return (0);
	return (1);
}

int		ft_check_params(t_params *params)
{
	if (params->empty != params->obstacle && params->empty !=
		params->full && params->obstacle != params->full)
		return (1);
	return (0);
}
