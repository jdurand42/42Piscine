/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_li.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:13:03 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 23:18:03 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "check_li.h"

int		check_li(int **sujet, int *soluce, int ligne, int direction)
{
	int		nombre_demande;
	int		i;
	int		j;
	int		plusgrand;
	int		compteplusgrand;

	plusgrand = 0;
	nombre_demande = direction == 1 ? sujet[2][ligne] : sujet[3][ligne];
	i = direction == 1 ? ligne * sujet[4][0] : (ligne + 1) * sujet[4][0] - 1;
	j = 0;
	compteplusgrand = 0;
	while (j < sujet[4][0])
	{
		if (soluce[i] > plusgrand)
		{
			compteplusgrand++;
			plusgrand = soluce[i];
		}
		j++;
		i += direction;
	}
	if (nombre_demande == compteplusgrand)
		return (1);
	return (0);
}

int		check_ci(int **sujet, int *soluce, int colonne, int direction)
{
	int		nombre_demande;
	int		i;
	int		j;
	int		plusgrand;
	int		compteplusgrand;

	plusgrand = 0;
	nombre_demande = direction == 1 ? sujet[0][colonne] : sujet[1][colonne];
	i = direction == 1 ? colonne : sujet[4][0] * (sujet[4][0] - 1) + colonne;
	j = 0;
	compteplusgrand = 0;
	while (j < sujet[4][0])
	{
		if (soluce[i] > plusgrand)
		{
			compteplusgrand++;
			plusgrand = soluce[i];
		}
		j++;
		i += direction * sujet[4][0];
	}
	if (nombre_demande == compteplusgrand)
		return (1);
	return (0);
}

int		check_lc(int **sujet, int *soluce, int ligne)
{
	int i;
	int j;
	int nombredematchs;

	i = 0;
	while (i < sujet[4][0])
	{
		j = ligne * sujet[4][0];
		nombredematchs = 0;
		while (j < (ligne + 1) * sujet[4][0])
		{
			if (soluce[j] == i + 1)
				nombredematchs++;
			j++;
		}
		if (nombredematchs != 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_cc(int **sujet, int *soluce, int colonne)
{
	int i;
	int j;
	int nombredematchs;

	i = 0;
	while (i < sujet[4][0])
	{
		j = colonne;
		nombredematchs = 0;
		while (j < sujet[4][0] * sujet[4][0])
		{
			if (soluce[j] == i + 1)
				nombredematchs++;
			j += sujet[4][0];
		}
		if (nombredematchs != 1)
			return (0);
		i++;
	}
	return (1);
}

int		checktout(int **sujet, int *soluce)
{
	int		i;

	i = 0;
	while (i < sujet[4][0])
	{
		if (check_li(sujet, soluce, i, 1) == 0)
			return (0);
		if (check_li(sujet, soluce, i, -1) == 0)
			return (0);
		if (check_lc(sujet, soluce, i) == 0)
			return (0);
		if (check_ci(sujet, soluce, i, 1) == 0)
			return (0);
		if (check_ci(sujet, soluce, i, -1) == 0)
			return (0);
		if (check_cc(sujet, soluce, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
