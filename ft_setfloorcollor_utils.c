/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfloorcollor_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 01:51:28 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/02 06:05:35 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_intlenn(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		countlenarr(char **arr)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (arr[i])
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

int		ft_strlast(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1])
			i++;
		else
			return (i);
	}
	return (i);
}

char	*ft_dostr(char **arr)
{
	int		i;
	char	*str;

	i = countlenarr(arr);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (arr[i])
	{
		if (ft_isdigit(str[ft_strlast(str)]) && ft_isdigit(arr[i][0]))
		{
			free(str);
			return (NULL);
		}
		ft_strlcat(str, arr[i], -1);
		i++;
	}
	return (str);
}

int		ft_checksymbols(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' || ft_isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
