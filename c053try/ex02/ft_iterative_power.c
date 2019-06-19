/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:41:14 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/17 15:52:44 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int resultat;

	resultat = 1;
	if (nb == 0 && power != 0)
		return (0);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		resultat = resultat * nb;
		power--;
	}
	return (resultat);
}
