/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:07:06 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 23:08:51 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "check_li.h"



int		main(int argc, char **argv)
{
	char	*index;
	int		**tableau;
	int		nombre_arguments;

	if (check_argv(argv[1]) == 1 && argc == 2)
	{
		index = malloc(37 * sizeof(char));
		index = initialize(argv[1], index);
		nombre_arguments = get_base_index(index);
		if (nombre_arguments > 0)
		{
			tableau = get_tab(index, nombre_arguments);
			inputtest(tableau);
		}
		else
		{
			ft_putstr("Error");
		}
	}
	else
		ft_putstr("Error");
	free(tableau);
	free(index);
	return (0);
}
