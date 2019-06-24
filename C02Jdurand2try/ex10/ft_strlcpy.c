/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:51:29 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/11 16:24:54 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	strlen_custom(char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	if (i < size && size > 0)
	{
		while (src[i] != '\0' && i < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (strlen_custom(src));
}
