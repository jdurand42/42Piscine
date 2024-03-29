/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:41:33 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/17 15:54:27 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int resultat;

	i = 1;
	resultat = 0;
	while (resultat <= nb && i < 46951)
	{
		resultat = i * i;
		if (resultat == nb)
			return (i);
		else if (resultat > nb)
			return (0);
		i++;
	}
	return (0);
}
