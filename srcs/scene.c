/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 06:59:00 by vyastrub          #+#    #+#             */
/*   Updated: 2018/01/20 16:12:26 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray		*new_ray(void)
{
	t_ray	*ray;

	ray = (t_ray*)malloc(sizeof(t_ray));
	ray->org = (t_vec*)malloc(sizeof(t_vec));
	ray->dir = (t_vec*)malloc(sizeof(t_vec));
	return (ray);
}

static void	init_flags(t_arr *gl)
{
	gl->lights = 0;
	gl->planes = 0;
	gl->spheres = 0;
	gl->cylindres = 0;
	gl->cones = 0;
	gl->tores = 0;
	gl->disks = 0;
	gl->parab = 0;
	gl->uv = -1;
	gl->grey = -1;
}

void		init(t_arr *gl)
{
	int i;
	int j;

	gl->cur = (t_current***)malloc(sizeof(t_current**) * THREADS);
	j = -1;
	while (++j < THREADS)
	{
		gl->cur[j] = (t_current**)malloc(sizeof(t_current*) * DEPTH);
		i = -1;
		while (++i <= DEPTH)
		{
			gl->cur[j][i] = (t_current *)malloc(sizeof(t_current));
			gl->cur[j][i]->ray = new_ray();
			gl->cur[j][i]->bck = new_ray();
			gl->cur[j][i]->i = 0;
			gl->cur[j][i]->id = j;
			gl->cur[j][i]->flag = 0;
			gl->cur[j][i]->col = (t_col*)malloc(sizeof(t_col));
			set_col(gl->cur[j][i]->col, 0, 0, 0);
		}
		gl->t[j] = 0;
		gl->t2[j] = 0;
	}
	init_flags(gl);
}

t_obj		*fill_obj(int fl, int i, int (*in)(), void (*n)())
{
	t_obj	*obj;

	obj = (t_obj*)malloc(sizeof(t_obj));
	obj->c = (t_vec*)malloc(sizeof(t_vec));
	obj->c2 = (t_vec*)malloc(sizeof(t_vec));
	obj->v = (t_vec*)malloc(sizeof(t_vec));
	obj->r = 0;
	obj->r2 = 0;
	obj->k = 0;
	obj->h = 0;
	obj->cap = 0;
	obj->index = i;
	obj->color = (t_col*)malloc(sizeof(t_col));
	obj->flag = fl;
	obj->diffuse = 0;
	obj->specular = 0;
	obj->reflection = 0;
	obj->refraction = 0;
	obj->intersect = in;
	obj->normal = n;
	return (obj);
}

t_obj		**new_obj(int c, t_arr *gl, int fl)
{
	t_obj	**obj;
	int		i;

	i = -1;
	obj = (t_obj **)malloc(sizeof(t_obj *) * c);
	while (++i < c)
	{
		if (fl == 1)
			obj[i] = fill_obj(fl, i, plane_inter, normal_spr_pln);
		else if (fl == 2)
			obj[i] = fill_obj(fl, i, spher_inter, normal_spr_pln);
		else if (fl == 3)
			obj[i] = fill_obj(fl, i, cylin_inter, normal_con_cyl);
		else if (fl == 4)
			obj[i] = fill_obj(fl, i, conus_inter, normal_con_cyl);
		else if (fl == 5)
			obj[i] = fill_obj(fl, i, torus_inter, normal_tor);
		else if (fl == 6)
			obj[i] = fill_obj(fl, i, disk_inter, normal_spr_pln);
		else if (fl == 7)
			obj[i] = fill_obj(fl, i, parab_inter, normal_prb);
	}
	gl->amb = 0;
	return (obj);
}
