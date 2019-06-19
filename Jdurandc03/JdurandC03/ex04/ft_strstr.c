/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 05:46:38 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/12 20:17:51 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i++] != '\0')
	{
		if ((to_find[j] == str[i]) && (str[i] != '\0') &&
				(to_find[j] != '\0'))
		{
			k = i;
			while ((to_find[j++] == str[++k]) && (str[k] != '\0') &&
				(to_find[j] != '\0'))
			{
				j++;
				k++;
			}
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		j = 0;
	}
	return (0);
}
