/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:29:37 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/09 12:48:12 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div;
	int mod;

	ft_div_mod(*a, *b, &div, &mod);
	*a = div;
	*b = mod;
}
