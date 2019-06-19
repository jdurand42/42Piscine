/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:48:10 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/19 16:48:12 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen_us(char *str)
{
	unsigned i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_is_valid(char *base)
{
	unsigned int i;
	unsigned int j;
	unsigned int base_len;

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

int	is_base(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	resultat;
	int base_len;

	if (!(base_len = base_is_valid(base)))
		return (0);
	resultat = 0;
	i = 0;
	neg = 1;
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
	}
	return (neg * resultat);
}
