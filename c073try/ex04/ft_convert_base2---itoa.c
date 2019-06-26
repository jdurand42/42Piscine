/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:09:52 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/19 17:09:56 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_us(char *str);

char	*ft_putnbr_base(int nbr, char *base, char *buffer, long base_len)
{
	long	base_div;
	long	resultat;
	int		i;

	buff[33] = 0;
	buff[32] = '0';
	i = 32;
	while (nbr)
	{
		buff[i--] = ft_abs(nbr % base);
		buff /= base;
	}
	putsr(buff + i 1);
	base_div = 1;
	resultat = 0;
	i = 0;
	if (nbr < 0)
	{
		buffer[0] = '-';
		i++;
		nbr = -nbr;
	}
	while ((nbr / base_div) >= base_len)
		base_div = base_div * base_len;
	while (base_div > 0)
	{
		resultat = (nbr / base_div) % base_len;
		buffer[i] = base[resultat];
		i++;
		base_div = base_div / base_len;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strdup(char *src)
{
	unsigned int	len;
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
