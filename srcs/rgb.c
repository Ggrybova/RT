/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:44:29 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:01:58 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	greyscale(double s, t_col *col)
{
	int	res;
	int	i;
	int	tmp;

	res = 0;
	tmp = 0;
	i = -1;
	while (++i < 3)
	{
		col->arr[i] = col->arr[i] * s;
		if (col->arr[i] > 255)
			col->arr[i] = 255;
		if (col->arr[i] < 0)
			col->arr[i] = 0;
		tmp += col->arr[i];
	}
	tmp /= 3;
	i = -1;
	while (++i < 3)
		col->arr[i] = tmp;
	return (res);
}

static int	ultraviolet(double s, t_col *col)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < 3)
	{
		col->arr[i] = col->arr[i] * s;
		if (col->arr[i] > 255)
			col->arr[i] = 255;
		if (col->arr[i] < 0)
			col->arr[i] = 0;
	}
	tmp = (222 * col->arr[2] + 707 * col->arr[1] + 71 * col->arr[0]) / 1000;
	col->arr[0] = (tmp << 24) >> 24;
	col->arr[1] = (tmp << 16) >> 24;
	col->arr[2] = (tmp << 8) >> 24;
	return (tmp);
}

int			getcol(t_arr *gl, t_col *col, t_current *cur)
{
	int		res;
	int		i;
	double	s;
	int		tmp;

	res = 0;
	s = 0;
	i = -1;
	while (++i < gl->lights)
		s += gl->src[cur->id][i]->lamb +
			(gl->src[cur->id][i]->fong * cur->gloss);
	if (gl->grey > 0)
		return (greyscale(s, col));
	if (gl->uv > 0)
		return (ultraviolet(s, col));
	i = -1;
	while (++i < 3)
	{
		col->arr[i] = col->arr[i] * s;
		(col->arr[i] > 255 ? col->arr[i] = 255 : 0);
		(col->arr[i] < 0 ? col->arr[i] = 0 : 0);
		tmp = col->arr[i];
		res = res | (tmp << 8 * i);
	}
	return (res);
}
