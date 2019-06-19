/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:47:07 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/17 16:26:22 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int resultat;

	if (power < 0)
		return (0);
	if (power == 0)
		resultat = 1;
	else
		resultat = nb * ft_recursive_power(nb, power - 1);
	return (resultat);
}
