/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:19:22 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/14 14:54:56 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int factorielle;

	factorielle = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		factorielle = factorielle * nb;
		nb--;
	}
	return (factorielle);
}
