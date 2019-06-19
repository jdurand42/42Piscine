/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:52:11 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/14 11:03:00 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_atoiable(char c)
{
	if (c == '+' || c == '-')
		return (1);
	if (c == ' ' || (c >= 9 && c <= 13))
		return (2);
	else
		return (0);
}

int	ft_is_number(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	resultat;

	resultat = 0;
	i = 0;
	neg = 1;
	while (str[i] != '\0' && (ft_is_atoiable(str[i]) == 2))
		i++;
	while (str[i] != '\0' && (ft_is_atoiable(str[i]) == 1))
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] != '\0' && (ft_is_number(str[i]) == 1))
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (neg * resultat);
}
