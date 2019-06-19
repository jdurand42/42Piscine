/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:24:58 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/09 14:25:00 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	j = 0;
	size = size - 1;
	while (j <= i)
	{
		i = 0;
		while (i + 1 <= size)
		{
			if (tab[i] > tab[i + 1])
			{
				buff = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = buff;
				i = 0;
			}
			i++;
		}
		j++;
	}
}
