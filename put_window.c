/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:55:14 by fbarbera          #+#    #+#             */
/*   Updated: 2020/10/03 08:24:16 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	putfloor(t_data *img, int i, int jj)
{
	int col;

	col = -1;
	while (col++ < img->coef)
	{
		my_mlx_pixel_put(img, img->r1 - i - col, jj, img->floor);
		my_mlx_pixel_put(img, img->r1 - i - col, img->r2 - jj - 1, img->cellar);
	}
}

void	ft_putline(t_data *img, int i, double pixelhiegt, double pofw)
{
	int		jj;
	int		end;
	int		collor;
	int		col;
	t_xpm	*wall;

	i = i * img->coef;
	wall = ft_findwall(img);
	if (i > img->r1)
		return ;
	set_start_end(pixelhiegt, img->r2, &end, &jj);
	while (++jj < img->r2 - 1)
	{
		if (jj < end)
		{
			collor = get_collor(wall, (pofw * wall->width), (wall->height * \
			ft_foundpixel(jj, pixelhiegt, img->r2)));
			col = -1;
			while (col++ < img->coef)
				my_mlx_pixel_put(img, img->r1 - i - col, jj, collor);
		}
		else
			putfloor(img, i, jj);
	}
}

void	pixelcount(t_data *img, double c, int *i, double angle1)
{
	double	pixelhiegt;
	double	partofwall;
	t_xpm	*wall;

	pixelhiegt = img->r2 / (c * cos(img->mainangle - angle1));
	wall = ft_findwall(img);
	partofwall = ft_findpartofwall(wall->name, img->mapx, img->mapy);
	ft_putline(img, *i, pixelhiegt, partofwall);
	img->deep[*i] = c;
	*i = *i + 1;
}

void	dostep1(double *c, double x, double y, double angle)
{
	double xx;
	double yy;

	if ((angle > 0 && angle <= M_PI_2) ||\
	(angle > 0 + 2 * M_PI && angle <= M_PI_2 + 2 * M_PI))
	{
		xx = (((int)x - x + 1) / cos(angle));
		yy = (((int)y - y + 1) / sin(angle));
	}
	else if (angle > M_PI_2 && angle < M_PI)
	{
		yy = (((int)y - y + 1) / sin(angle));
		xx = (x - (int)x) / (cos(correctangle(angle)));
		if (fabs(xx) == 0)
			yy = fabs(yy) + 0.000001;
		else if (fabs(yy) == 0)
			xx = fabs(xx) + 0.000001;
		else if (fabs(xx) < fabs(yy))
			xx = fabs(xx) + 0.000001;
		else
			yy = fabs(yy) + 0.000001;
	}
	else if (angle <= -M_PI_2 + 2 * M_PI && angle >= M_PI)
	{
		xx = (x - (int)x) / (cos(correctangle(angle)));
		yy = (y - (int)y) / (sin(correctangle(angle)));
		if (fabs(xx) == 0)
			yy = fabs(yy) + 0.000001;
		else if (fabs(yy) == 0)
			xx = fabs(xx) + 0.000001;
		else if (fabs(xx) < fabs(yy))
			xx = fabs(xx) + 0.000001;
		else
			yy = fabs(yy) + 0.000001;
	}
	else
	{
		xx = (((int)x - x + 1) / cos(angle));
		yy = (y - (int)y) / (sin(correctangle(angle)));
		if (fabs(xx) == 0)
			yy = fabs(yy) + 0.000001;
		else if (fabs(yy) == 0)
			xx = fabs(xx) + 0.000001;
		else if (fabs(xx) < fabs(yy))
			xx = fabs(xx) + 0.000001;
		else
			yy = fabs(yy) + 0.000001;
	}
	if (fabs(xx) == 0)
		*c = *c + fabs(yy);
	else if (fabs(yy) == 0)
		*c = *c + fabs(xx);
	else if (fabs(xx) < fabs(yy))
		*c = *c + fabs(xx);
	else
		*c = *c + fabs(yy);
}

void	dostep(double *c, double x, double y)
{
	double xx;
	double yy;

	xx = x - (int)x;
	yy = y - (int)y;
	if (xx > 0.3 && xx < 0.7 && yy > 0.3 && yy < 0.7)
		*c = *c + 0.3;
	else if (xx > 0.1 && xx < 0.9 && yy > 0.1 && yy < 0.9)
		*c = *c + 0.1;
	else
		*c = *c + 0.01 ;
}

t_data	*ft_putcol(t_data *img)
{
	double	c;
	double	angle1;
	int		i;

	angle1 = img->mainangle - M_PI / 6;
	if (!(img->deep = malloc(sizeof(double) * (img->r1 / img->coef + 3))))
		exit(pritnerror(freexmp4(img)));
	i = 0;
	while (angle1 < img->mainangle + M_PI / 6)
	{
		c = 0.001;
		while (wallfounder(img, c, angle1) != 1)
			dostep1(&c, img->mapx, img->mapy, angle1);
		// c = c - 0.01;
		// while (wallfounder(img, c, angle1) != 1)
		// 	c = c + 0.002;
		pixelcount(img, c, &i, angle1);
		angle1 += M_PI * img->coef / (img->r1 * 3);
	}
	return (img);
}

void	ft_putwindow_3d(t_data *img)
{
	ft_putcol(img);
	ft_putsprite(img);
	ft_putonelinepixel(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
}
