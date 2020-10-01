/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:10 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/01 19:48:25 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	setdata(tmp, img, flag);
	img->flag = flag;
	free(line);
	freemass(tmp);
}

void	ft_parser(char **argv, t_data *img)
{
	int			fd;
	char		*line;
	t_list		*list;
	t_flags		*flag;

	list = NULL;
	errno = 0;
	if (!(flag = malloc(sizeof(t_flags))))
		exit(pritnerror(0));
	ft_cleanflag(flag);
	if ((fd = open(argv[1], O_RDWR)) <= 0)
		exit(pritnerror(999));
	if (ft_errnocheck(errno, flag, fd))
		exit(0);
	while (get_next_line(fd, &line))
	{
		if (line == NULL || line[0] == '\0')
			free(line);
		else if (fl_sumflag(flag) > 7 && line[0] != '\0')
			ft_lstadd_back(&list, ft_lstnew(line));
		else if (line[0])
			ft_persetdata(img, flag, line);
	}
	if (line == NULL || line[0] == '\0')
	{
		if (fl_sumflag(flag) < 7)
		{
			free(flag);
			ft_putstr_fd("ERROR\nFILE DATA\n", 2);
			exit(0);
		}
	}
	else 
		ft_lstadd_back(&list, ft_lstnew(line));
	close(fd);
	img->map = ft_bigarr(ft_create_arr(list, flag, img), img);
	ft_checkmap(img->map, img);
	if (!(img->spr = malloc(sizeof(t_sprite) * img->num)))
	{
		printf("dsdfsdfs\n");
		exit(pritnerror(freexmp5(img)));
	}
}
