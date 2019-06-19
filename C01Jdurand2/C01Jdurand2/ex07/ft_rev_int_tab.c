/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:56:33 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/10 12:55:16 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int buffer;
	int i;

	i = 0;
	size = size - 1;
	while (size > i)
	{
		buffer = tab[size];
		tab[size] = tab[i];
		tab[i] = buffer;
		size--;
		i++;
	}
}
