/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:45:49 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/22 03:55:15 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(s1 = malloc(sizeof(char) * i + 1)))
		return (0);
	j = 0;
	while (j <= i)
	{
		s1[j] = src[j];
		j++;
	}
	return (s1);
}
