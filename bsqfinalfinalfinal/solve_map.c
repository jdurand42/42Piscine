/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:00:49 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/26 20:05:00 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_solve(int x, int y, t_coord *bigger, int **t)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	ft_init_bigger(bigger);
	while (++j < y)
	{
		while (++i < x && j < y)
		{
			if (i != 0 && j != 0 && t[j][L] >= t[j][i] &&
					t[U][i] >= t[j][i] && t[U][L] >= t[j][i] && t[j][i] != -1)
			{
				t[j][i] = ft_comp(t[j][L], t[U][i], t[U][L]);
				ft_is_bigger(bigger, i, j, t[j][i]);
			}
			else if (t[j][i] != -1)
			{
				t[j][i] = 1;
				ft_is_bigger(bigger, i, j, t[j][i]);
			}
		}
		i = -1;
	}
	return (t);
}

void	ft_is_bigger(t_coord *bigger, int i, int j, int pos)
{
	if (pos > bigger->value)
	{
		bigger->x = i;
		bigger->y = j;
		bigger->value = pos;
	}
}

int		ft_comp(int left, int up, int diag)
{
	int smaller;

	smaller = left;
	if (smaller > diag)
		smaller = diag;
	if (smaller > up)
		smaller = up;
	return (smaller + 1);
}

void	ft_init_bigger(t_coord *bigger)
{
	bigger->x = 0;
	bigger->y = 0;
	bigger->value = 0;
}
