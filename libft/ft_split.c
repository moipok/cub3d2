/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:18:51 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/27 02:50:07 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countrow(char const *s, char c)
{
	int	row;

	row = 1;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (*s != '\0')
				row++;
		}
		else
			s++;
	}
	return (row);
}

static int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while ((*s != c) && (*s))
	{
		s++;
		i++;
	}
	return (i);
}

static void	ft_freearr(char **str, int row)
{
	while (row >= 0)
	{
		free(str[row]);
		row--;
	}
	free(str);
}

static char	**ft_ilovemy26lines(char **str, char c, int row, const char *s)
{
	int	i;
	int	len;

	i = -1;
	while (i++ < row)
	{
		while (*s == c && *s)
			s++;
		len = ft_len(s, c);
		if (*s == '\0')
			str[i] = NULL;
		else
		{
			if (!(str[i] = ft_substr(s, 0, len)))
			{
				ft_freearr(str, i);
				return (NULL);
			}
			s = s + len;
		}
	}
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		row;

	if ((!(s)) || !(row = ft_countrow(s, c)))
		return (NULL);
	if (!(str = (char **)ft_calloc(sizeof(char *), row + 1)))
		return (NULL);
	if (!(str = ft_ilovemy26lines(str, c, row, s)))
		return (NULL);
	return (str);
}
