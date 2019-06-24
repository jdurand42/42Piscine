/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:40:20 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/11 16:40:15 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		char_is_alphanumeric(char c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') &&
			!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	return (1);
}

int		char_is_lowcase(char c)
{
	if (!(c >= 'a' && c <= 'z'))
	{
		return (0);
	}
	return (1);
}

void	charlowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	if (char_is_alphanumeric(str[0]) && char_is_lowcase(str[0]))
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		while (!(char_is_alphanumeric(str[i])) &&
				str[i] != '\0')
		{
			i++;
			if (char_is_alphanumeric(str[i]))
			{
				if (char_is_lowcase(str[i]))
					str[i] = str[i] - 32;
			}
		}
		while ((char_is_alphanumeric(str[i])) && str[i] != '\0')
		{
			i++;
			charlowcase(&str[i]);
		}
	}
	return (str);
}
