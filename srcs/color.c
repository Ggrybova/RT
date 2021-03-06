/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:27:49 by vyastrub          #+#    #+#             */
/*   Updated: 2018/01/20 12:44:47 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	light(t_current *cur, t_lsrc *src)
{
	t_vec	v;
	t_vec	h;
	t_vec	l;

	l = add(src->lgt, &cur->p, 2);
	norm(&l);
	src->lamb = dot(&cur->n, &l);
	if (cur->gloss == 0)
	{
		src->fong = 0;
		return ;
	}
	v = add(cur->ray->org, &cur->p, 2);
	norm(&v);
	h = add(&v, &l, 1);
	norm(&h);
	src->fong = pow(dot(&cur->n, &h), 800);
}

void	normal_spr_pln(t_current *cur)
{
	if (cur->flag != 2)
		cur->n = *(cur->obj->v);
	else
		cur->n = add(&cur->p, cur->obj->c, 2);
	norm(&cur->n);
}

void	normal_con_cyl(t_current *cur)
{
	t_vec	l;
	double	s;

	cur->n = mul(cur->obj->v, cur->dt, 1);
	l = add(cur->ray->org, cur->obj->c, 2);
	s = dot(cur->ray->dir, &cur->n) + dot(&l, cur->obj->v);
	l = mul(cur->obj->v, (s * (1 + pow(cur->obj->k, 2))), 1);
	cur->n = add(&cur->p, cur->obj->c, 2);
	cur->n = add(&cur->n, &l, 2);
	norm(&cur->n);
}

void	normal_tor(t_current *cur)
{
	double	y;
	t_vec	tmp;
	t_vec	d;
	t_vec	x;

	norm(cur->obj->v);
	tmp = add(&cur->p, cur->obj->c, 2);
	y = dot(&tmp, cur->obj->v);
	d = mul(cur->obj->v, y, 1);
	d = add(&tmp, &d, 2);
	x = mul(&d, cur->obj->r / sqrt(dot(&d, &d)), 1);
	cur->n = add(&tmp, &x, 2);
	norm(&cur->n);
}

void	normal_prb(t_current *cur)
{
	t_vec	l;
	double	m;

	l = add(&cur->p, cur->obj->c, 2);
	m = dot(&l, cur->obj->v);
	cur->n = mul(cur->obj->v, m + cur->obj->r2, 1);
	cur->n = add(&l, &cur->n, 2);
	norm(&cur->n);
}
