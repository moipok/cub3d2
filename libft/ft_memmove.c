/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 02:00:59 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/22 03:11:32 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ds;
	const char	*sr;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = -1;
	ds = (char *)dest;
	sr = (char *)src;
	if (ds > sr)
		while (++i < n)
			ds[n - i - 1] = sr[n - i - 1];
	else
		while (++i < n)
			ds[i] = sr[i];
	return (ds);
}
