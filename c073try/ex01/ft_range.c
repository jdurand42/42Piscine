/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:30:01 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/21 15:31:17 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*range;
	long	i;

	i = 0;
	range = NULL;
	if (!(max > min))
		return (0);
	else
	{
		if (!(range = (int*)malloc((max - min + 1) * sizeof(int))))
			return (0);
		while (min + i < max)
		{
			range[i] = min + i;
			i++;
		}
		range[i] = '\0';
		return (range);
	}
}
