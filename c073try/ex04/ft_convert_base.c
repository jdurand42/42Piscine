/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:06:17 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/23 12:28:23 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);
char	*ft_putnbr_base(int nbr, char *base, char *buffer, long base_len);

int		ft_strlen_us(char *str)
{
	unsigned i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		base_is_valid(char *base)
{
	int		i;
	int		j;
	long	base_len;

	i = 0;
	j = 1;
	base_len = ft_strlen_us(base);
	if (base_len < 2)
		return (0);
	while (i < base_len)
	{
		if (!(base[i] >= 33 && base[i] <= 126) ||
				base[i] == '+' || base[i] == '-')
			return (0);
		while (j < base_len)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (base_len);
}

int		is_base(char c, char *base)
{
	unsigned int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base, int *verif_nb)
{
	int		i;
	int		neg;
	long	resultat;
	int		base_len;

	resultat = 0;
	i = 0;
	neg = 1;
	base_len = ft_strlen_us(base);
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] != '\0' && is_base(str[i], base) != -1)
	{
		resultat = resultat * base_len + is_base(str[i], base);
		i++;
		*verif_nb = *verif_nb + 1;
	}
	return (neg * resultat);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_base10;
	char	buffer[34];
	char	*nb_to_base;
	int		verif_nb;
	int		base_len;

	verif_nb = 0;
	nbr_base10 = 0;
	if (!(base_is_valid(base_from)))
		return (0);
	if (!(base_is_valid(base_to)))
		return (0);
	nbr_base10 = ft_atoi_base(nbr, base_from, &verif_nb);
	base_len = ft_strlen_us(base_to);
	ft_putnbr_base(nbr_base10, base_to, buffer, base_len);
	nb_to_base = ft_strdup(buffer);
	if (verif_nb > 0)
		return (nb_to_base);
	else
		return ("0");
}

int main(int argc, char **argv)
{
	printf("%s", ft_convert_base(argv[1], argv[2], argv[3]));
}
