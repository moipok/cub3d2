/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:23:52 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/07 00:55:50 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	int flag;

	flag = 0;
	while (*str)
	{
		if (*str == ch)
			flag = 1;
		str++;
	}
	while (flag == 1)
	{
		if (*str == ch)
			return ((char *)str);
		str--;
	}
	if (ch == '\0')
		return ((char *)str);
	return (0);
}
