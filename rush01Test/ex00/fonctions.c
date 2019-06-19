/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:29:46 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 23:29:50 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_li.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	affichetout(int **sujet, int *soluce)
{
	int	i;

	i = 0;
	while (i < sujet[4][0] * sujet[4][0])
	{
		ft_putchar('0' + soluce[i]);
		ft_putchar(' ');
		if (i % sujet[4][0] == sujet[4][0] - 1)
			ft_putchar('\n');
		i++;
	}
}

int		checkuneligne(int **sujet, int *soluce, int position)
{
	if (check_lc(sujet, soluce, position / sujet[4][0]) == 0)
		return (0);
	if (check_li(sujet, soluce, position / sujet[4][0], 1) == 0)
		return (0);
	if (check_li(sujet, soluce, position / sujet[4][0], -1) == 0)
		return (0);
	return (1);
}

int		checkunecolonne(int **sujet, int *soluce, int position)
{
	if (check_cc(sujet, soluce, position % sujet[4][0]) == 0)
		return (0);
	if (check_ci(sujet, soluce, position % sujet[4][0], 1) == 0)
		return (0);
	if (check_ci(sujet, soluce, position % sujet[4][0], -1) == 0)
		return (0);
	return (1);
}

void	solve(int **sujet, int *soluce, int position)
{
	int i;

	i = -1;
	while (i++ < sujet[4][0])
	{
		soluce[position] = i + 1;
		if ((position % sujet[4][0]) == sujet[4][0] - 1)
			if (checkuneligne(sujet, soluce, position) == 0)
				continue;
		if ((position / sujet[4][0]) == sujet[4][0])
			if (checkunecolonne(sujet, soluce, position) == 0)
				continue;
		if (position == (sujet[4][0] * sujet[4][0]) - 1)
		{
			if (checktout(sujet, soluce) == 1)
				affichetout(sujet, soluce);
		}
		else
			solve(sujet, soluce, position + 1);
	}
}

int		inputtest(int **sujet)
{
	int	soluce[sujet[4][0] * sujet[4][0]];

	solve(sujet, soluce, 0);
	return (0);
}
