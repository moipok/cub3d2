/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:54:10 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/01 23:58:34 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	postparser(t_data *img, t_flags *flag, t_list *list, int fd)
{
	close(fd);
	img->map = ft_bigarr(ft_create_arr(list, flag, img), img);
	ft_checkmap(img->map, img);
	if (!(img->spr = malloc(sizeof(t_sprite) * img->num)))
		exit(pritnerror(freexmp5(img)));
}

int		ft_openfile(char *argv, t_flags *flag)
{
	int fd;

	errno = 0;
	if ((fd = open(argv, O_RDWR)) <= 0)
		exit(pritnerror(999));
	if (ft_errnocheck(errno, flag, fd))
		exit(0);
	return (fd);
}

void	ft_parser1(char **argv, t_data *img, t_flags *flag)
{
	int			fd;
	char		*line;
	t_list		*list;

	list = NULL;
	fd = ft_openfile(argv[1], flag);
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			free(line);
		else if (fl_sumflag(flag) > 7)
			ft_lstadd_back(&list, ft_lstnew(line));
		else if (line[0])
			ft_persetdata(img, flag, line);
		else
			free(line);
	}
	if (fl_sumflag(flag) < 7)
		exit(pritnerror(error_setdatar99(flag, img)));
	else
		ft_lstadd_back(&list, ft_lstnew(line));
	postparser(img, flag, list, fd);
}

void	ft_parser(char **argv, t_data *img)
{
	t_flags	*flag;

	img->coef = 1;
	if (!(flag = malloc(sizeof(t_flags))))
		exit(pritnerror(0));
	ft_cleanflag(flag);
	ft_parser1(argv, img, flag);
}
