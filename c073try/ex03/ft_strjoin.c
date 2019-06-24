/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:14:04 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/22 17:58:54 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	get_megasize(unsigned int *megasize, char **strs, int size, char *sep)
{
	int i;

	i = 0;
	while (i < size)
	{
		*megasize = *megasize + ft_strlen(strs[i]);
		i++;
	}
	*megasize = *megasize + ((size) * ft_strlen(sep) + 1);
}

char	*cat(int size, char **strs, char *sep, char *buffer)
{
	int	i;
	int	marker;

	i = 0;
	marker = 0;
	while (i < size)
	{
		if (size > 0 && i > 0)
			ft_strcat(buffer, sep);
		ft_strcat(buffer, strs[i]);
		marker = 1;
		i++;
	}
	return (buffer);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	megasize;
	char			*buffer;

	megasize = 0;
	if (size <= 0)
	{
		buffer = malloc(1 * sizeof(char));
		buffer[0] = '\0';
		return (buffer);
	}
	get_megasize(&megasize, strs, size, sep);
	if (!(buffer = (char*)malloc(megasize * sizeof(char))))
		return (0);
	buffer[0] = '\0';
	cat(size, strs, sep, buffer);
	return (buffer);
}
