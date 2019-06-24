/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:31:18 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/24 14:20:16 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int		ft_strcmp(char c, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (c == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc((n + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (src[i] != '\0' && i < n)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

char	**ft_count_words(char *str, char *charset, int *count_words)
{
	int		i;
	char	**tab;

	i = 0;
	*count_words = 0;
	while (str[i] != '\0')
	{
		if (ft_strcmp(str[i], charset) == 1)
			if (i > 0)
				if (ft_strcmp(str[i - 1], charset) == 0)
					*count_words = *count_words + 1;
		i++;
	}
	if (ft_strcmp(str[ft_strlen(str) - 1], charset) != 1)
		*count_words = *count_words + 1;
	if (!(tab = (char**)malloc((*count_words + 1) * sizeof(char*))))
		return (0);
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**tab;
	int		pos;
	int		count_words;

	i = 0;
	j = 0;
	pos = 0;
	tab = ft_count_words(str, charset, &count_words);
	while (str[i++] != '\0' && count_words > 0)
	{
		if (ft_strcmp(str[pos], charset) == 1)
			pos++;
		if (ft_strcmp(str[i], charset) == 1 && i > 0 &&
				ft_strcmp(str[i - 1], charset) == 0)
		{
			tab[j++] = ft_strndup(&str[pos], (i - pos));
			pos = i;
		}
	}
	if (count_words > 0 && ft_strcmp(str[ft_strlen(str) - 1], charset) != 1)
		tab[j++] = ft_strndup(&str[pos], (i - pos));
	tab[j] = 0;
	return (tab);
}

int main()
{
	char str[] = "9999MARCEL99d99/HENRI**LOLLOL//L///Adsds";
	char charset[] = "/9*";
	char **richard;
	richard = ft_split(str, charset);
	int i = 0;
	for (i = 0; i <= 6; i++)
	{
		printf("%s\n", richard[i]);
	}


	return (0);
}
