/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:41:35 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 22:53:03 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "check_li.h"

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		check_argv(char *str)
{
	unsigned int i;
	unsigned int len;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (len > 71 || len < 17)
		return (0);
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (0);
	while (i < len - 1)
	{
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == ' '))
			i++;
		else if (str[i] == ' ' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		else
			return (0);
	}
	if (!(str[len - 1] >= '0' && str[len - 1] <= '9'))
		return (0);
	return (1);
}

char	*initialize(char *str, char *index)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			index[j] = str[i];
			j++;
		}
		i++;
	}
	index[j] = '\0';
	return (index);
}

int		get_base_index(char *str)
{
	int		i;
	char	nombre_arguments;
	int		index_len;

	i = 0;
	index_len = 0;
	nombre_arguments = '0';
	while (str[index_len] != '\0')
		index_len++;
	if ((index_len) % 4 != 0)
		return (0);
	nombre_arguments = (index_len / 4) + '0';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '1')
			return (0);
		if (str[i] > (nombre_arguments))
			return (0);
		i++;
	}
	return (nombre_arguments - 48);
}

int		**get_tab(char *str, int nombre_arguments)
{
	int **tab;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = -1;
	tab = malloc(9 * sizeof(int));
	while (str[++k] != '\0')
	{
		if (i == 0)
			tab[j] = malloc(9 * sizeof(int));
		tab[j][i] = str[k] - 48;
		i++;
		if (i == nombre_arguments)
		{
			i = 0;
			j++;
		}
	}
	tab[4] = malloc(4 * sizeof(int));
	tab[4][0] = nombre_arguments;
	return (tab);
}
