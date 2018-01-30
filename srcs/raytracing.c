/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:27:48 by vyastrub          #+#    #+#             */
/*   Updated: 2018/01/20 21:00:45 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	set_distance(t_arr *gl, t_current *current, t_obj *obj)
{
	if (current->dt > 1e-4 && gl->t[current->id] >= current->dt)
		return ;
	current->obj = obj;
	current->dt = gl->t[current->id];
	current->flag = obj->flag;
	set_col(current->col, obj->color->r, obj->color->g, obj->color->b);
	current->gloss = obj->specular;
	current->i = obj->index;
	current->mirror = obj->reflection;
	current->ref_c = obj->refraction;
	current->normal = obj->normal;
	if (current->cap)
		current->normal = normal_spr_pln;
	current->cap = 0;
}

int		inshadow(t_arr *gl, t_obj **all, t_current *cur, double dist)
{
	int i;

	i = -1;
	while (++i < gl->total)
		if (all[i]->intersect(gl, cur->bck, all[i], cur->id))
			if (gl->t[cur->id] > 0 && gl->t[cur->id] < dist)
				if (all[i]->refraction <= 1)
					return (1);
	return (0);
}

void	tracing(t_arr *gl, t_current **cur, int x, t_pthr_data *data)
{
	int i;

	gl->iter[data->id] = 0;
	cur[0]->flag = 0;
	cur[0]->dt = 0;
	create_v(cur[0]->ray->dir, gl->res[data->y][x].x,
		gl->res[data->y][x].y, gl->res[data->y][x].z);
	write_sub(cur[0]->ray->dir, cur[0]->ray->dir, cur[0]->ray->org);
	norm(cur[0]->ray->dir);
	detection(gl, cur[0]->ray, cur, gl->iter[data->id]);
	if (cur[0]->flag)
	{
		universal(gl, cur, gl->iter[data->id]);
		i = -1;
		while (++i < gl->lights)
			render(gl, cur[gl->iter[data->id]], gl->src[data->id][i]);
		getcol(data->gl, cur[gl->iter[data->id]]->col, cur[0]);
		gl->cl[x][data->y].r = cur[gl->iter[data->id]]->col->arr[2];
		gl->cl[x][data->y].g = cur[gl->iter[data->id]]->col->arr[1];
		gl->cl[x][data->y].b = cur[gl->iter[data->id]]->col->arr[0];
	}
}

void	*raytrace(void *thread_data)
{
	int			x;
	t_pthr_data	*data;

	data = (t_pthr_data*)thread_data;
	while (++data->y < data->max_y)
	{
		x = -1;
		while (++x < W)
			tracing(data->gl, data->cur, x, data);
	}
	return (0);
}

void	make_pthreads(t_arr *gl)
{
	int			k;
	pthread_t	*threads;
	t_pthr_data	*thread_data;

	threads = (pthread_t*)malloc(THREADS * sizeof(pthread_t));
	thread_data = (t_pthr_data*)malloc(THREADS * sizeof(t_pthr_data));
	k = -1;
	while (++k < THREADS)
	{
		thread_data[k].y = H * k / THREADS - 1;
		thread_data[k].max_y = H * (k + 1) / THREADS;
		thread_data[k].gl = gl;
		thread_data[k].id = k;
		thread_data[k].cur = gl->cur[k];
		pthread_create(&(threads[k]), NULL, raytrace, &thread_data[k]);
	}
	k = -1;
	while (++k < THREADS)
		pthread_join(threads[k], NULL);
	free(threads);
	free(thread_data);
}
