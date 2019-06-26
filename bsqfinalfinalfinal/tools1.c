/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:40:34 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 22:11:32 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if ((copy = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *src1, char *src2)
{
	char	*new;
	int		new_size;

	new_size = ft_strlen(src1) + ft_strlen(src2);
	if ((new = (char*)malloc(sizeof(char) * new_size + 1)) == NULL)
		return (NULL);
	new[0] = '\0';
	ft_strcat(new, src1);
	ft_strcat(new, src2);
	free(src1);
	return (new);
}

void	ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_open_file(char *file_name)
{
	int file_descriptor;

	if (open(file_name, O_DIRECTORY) != -1)
		return (-1);
	file_descriptor = open(file_name, O_RDONLY);
	return (file_descriptor);
}
