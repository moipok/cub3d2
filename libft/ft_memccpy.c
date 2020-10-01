/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 01:47:55 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/24 01:11:54 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ds;
	unsigned char	*sr;
	unsigned char	cc;

	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	cc = (unsigned char)c;
	ds = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (i < n)
	{
		ds[i] = sr[i];
		if (ds[i] == cc)
			return (ds + 1 + i);
		i++;
	}
	return (NULL);
}
