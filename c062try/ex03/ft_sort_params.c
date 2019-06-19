/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:47:39 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/17 13:45:00 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			ft_swap(&argv[i], &argv[i + 1]);
			i = 1;
		}
		else
			i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
