/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 03:27:51 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/21 06:04:18 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (0);
	if (!(str = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (0);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strlcat(str, s1, -1);
	ft_strlcat(str, s2, -1);
	return (str);
}
