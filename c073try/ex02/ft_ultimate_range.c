/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:11:14 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/22 17:56:57 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	buffering(int max, int min, int **range)
{
	if (!(max > min))
	{
		*range = NULL;
		return (0);
	}
	else
		return (1);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	long	i;
	int		*tab;

	if (!(buffering(max, min, range)))
		return (0);
	i = 0;
	if (!(tab = (int*)malloc((max - min) * sizeof(int))))
		return (-1);
	while ((min + i) < max)
	{
		tab[i] = min + i;
		i++;
	}
	if (i >= 0)
	{
		*range = tab;
		return (i);
	}
	else
		return (-1);
}
