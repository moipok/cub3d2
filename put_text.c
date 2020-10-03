/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:09 by fbarbera          #+#    #+#             */
/*   Updated: 2020/09/27 23:52:06 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_putonelinepixel(t_data *img)
{
	int i;

	i = 0;
	while (i < img->r1)
	{
		my_mlx_pixel_put(img, i, 0, get_collordata(img, i, 1));
		i++;
	}
}

char		*cut_spases(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i < 0)
		return (NULL);
	i--;
	while (str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	return (str);
}
