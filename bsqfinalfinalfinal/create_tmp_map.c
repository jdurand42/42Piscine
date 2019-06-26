/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmp_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:41:54 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 22:09:56 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "bsq.h"

char	*ft_create_tmp(char *file_name, char *tmp_map)
{
	int		file_descriptor;
	int		ret;
	char	buffer[BUFFER_SIZE + 1];

	file_descriptor = ft_open_file(file_name);
	if (file_descriptor == -1)
		return (NULL);
	ret = 0;
	buffer[0] = '\0';
	if ((tmp_map = ft_strdup("\0")) == NULL)
		return (NULL);
	while ((ret = read(file_descriptor, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		if ((tmp_map = ft_strjoin(tmp_map, buffer)) == NULL)
			return (NULL);
	}
	close(file_descriptor);
	return (tmp_map);
}

char	*ft_create_tmp_stdin(char *tmp_map)
{
	int		ret;
	char	buffer[BUFFER_SIZE + 1];

	ret = 0;
	buffer[0] = '\0';
	if ((tmp_map = ft_strdup("\0")) == NULL)
		return (NULL);
	while ((ret = read(1, buffer, BUFFER_SIZE)))
	{
		buffer[ret] = '\0';
		if ((tmp_map = ft_strjoin(tmp_map, buffer)) == NULL)
			return (NULL);
	}
	return (tmp_map);
}
