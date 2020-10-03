/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:19 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/03 09:19:13 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_cleanflag(t_flags *flag)
{
	flag->noflag = 0;
	flag->soflag = 0;
	flag->weflag = 0;
	flag->eaflag = 0;
	flag->spriteflag = 0;
	flag->r1flag = 0;
	flag->cellarflag = 0;
	flag->floorflag = 0;
	flag->allflag = 0;
}

int			fl_sumflag(t_flags *flag)
{
	return (flag->noflag + flag->soflag + flag->weflag + \
	flag->eaflag + flag->spriteflag + flag->r1flag + \
	flag->cellarflag + flag->floorflag);
}

int			setfc(char s, t_flags *flag, char **str, t_data *img)
{
	if (s == 'F')
		flag->floorflag = 1;
	else if (s == 'C')
		flag->cellarflag = 1;
	return (ft_setfloorcollor(str, img));
}

int			ft_setr(t_data *img, t_flags *flag, char **str)
{
	int sizex;
	int sizey;

	sizex = 0;
	sizey = 0;
	if (str[1] == NULL || str[2] == NULL)
		exit(pritnerror(error_setdatar1(flag, img)));
	img->r1 = ft_atoi(str[1]);
	img->r2 = ft_atoi(str[2]);
	if (str[1][ft_intlenn(img->r1)] != '\0' ||\
	str[2][ft_intlenn(img->r2)] != '\0' || str[3] != NULL)
		exit(pritnerror(error_setdatar1(flag, img)));
	if (img->r1 < 0 || img->r2 < 0)
		exit(pritnerror(error_setdatar1(flag, img)));
	mlx_get_screen_size(img->mlx, &sizex, &sizey);
	if (img->r1 > sizex)
		img->r1 = sizex;
	if (img->r2 > sizey)
		img->r2 = sizey;
	return (1);
}

void		setdata(char **str, t_data *img, t_flags *flag, char *line)
{
	flag->allflag = fl_sumflag(flag);
	if (str[0] == NULL)
		exit(pritnerror(error_setdatar777(flag, img)));
	else if (str[0][0] == 'R' && !flag->r1flag && str[0][1] == '\0')
		flag->r1flag = ft_setr(img, flag, str);
	else if (str[0][0] == 'N')
		img->no = setno(str, flag, img, line);
	else if (str[0][0] == 'S' && str[0][1] == 'O' && !flag->soflag)
		img->so = setso(str, flag, img, line);
	else if (str[0][0] == 'S' && ft_strlen(str[0]) == 1 && !flag->spriteflag)
		img->sprite = setsprite(str, flag, img, line);
	else if (str[0][0] == 'W')
		img->we = setwe(str, flag, img, line);
	else if (str[0][0] == 'E')
		img->ea = setea(str, flag, img, line);
	else if (str[0][0] == 'F' && !flag->floorflag && str[0][1] == '\0')
		img->floor = setfc('F', flag, str, img);
	else if (str[0][0] == 'C' && !flag->cellarflag && str[0][1] == '\0')
		img->cellar = setfc('C', flag, str, img);
	else
		exit(pritnerror(error_setdatar777(flag, img)));
}
