/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 02:02:40 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/22 14:14:52 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen_us(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int				len;
	unsigned int	i;
	char			*dest;

	i = 0;
	len = ft_strlen_us(src);
	if (!(dest = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	else
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*tab;

	i = 0;
	tab = (struct s_stock_str*)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (tab == NULL)
		return (0);
	while (i < ac)
	{
		tab[i].size = ft_strlen_us(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
