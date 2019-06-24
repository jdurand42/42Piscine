/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:52:36 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/11 16:36:16 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	hexa_conv(unsigned char c)
{
	char			*hexa_tab;
	unsigned char	c1;
	unsigned char	c2;

	hexa_tab = "0123456789abcdef";
	c1 = hexa_tab[c / 16];
	c2 = hexa_tab[c % 16];
	ft_putchar('\\');
	ft_putchar(c1);
	ft_putchar(c2);
}

int		char_is_printable(unsigned char c)
{
	if (!(c >= 32 && c <= 126))
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(char_is_printable(str[i])))
		{
			hexa_conv(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	hexa_conv(str[i]);
}
