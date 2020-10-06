/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:02:44 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/06 13:02:46 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checktrash(char **arr)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 1;
	while (flag && arr[i])
	{
		j = 0;
		while (arr[i][j] && flag)
		{
			if (ft_strchr("01SNEW2", arr[i][j]))
				flag = 0;
			j++;
		}
		i++;
	}
	while (arr[i] && arr[i][0] != '\0')
		i++;
	while (arr[i])
	{
		if (arr[i][0] != '\0')
			exit(pritnerror(5));
		i++;
	}
}

char	**ft_bigarr(char **arr, t_data *img)
{
	char	**new;
	int		i;
	int		j;

	new = mallocbigarr(arr, img);
	img->num = 0;
	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == ' ')
				new[i][j] = '1';
			else
				new[i][j] = arr[i][j];
			if (arr[i][j] == '2')
				img->num++;
		}
	}
	freemass(arr);
	return (new);
}

void	ft_persetdata(t_data *img, t_flags *flag, char *line)
{
	char **tmp;

	if (!(tmp = ft_split(line, ' ')))
		exit(pritnerror(0));
	setdata(tmp, img, flag, line);
	img->flag = flag;
	free(line);
	freemass(tmp);
}
