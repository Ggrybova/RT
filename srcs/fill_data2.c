/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:43:49 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 16:51:39 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	fill_data_sp(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	get_data_from_sp(gl, k);
	i = -1;
	step = 100;
	while (++i < 8)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->sp[k].info[i], (SDL_Color)COLOR_BLUE);
		gl->menu->sp[k].t_text_sp[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->sp[k].t_text_sp[i], NULL, NULL,
			&gl->menu->sp[k].r_text_sp[i].w, &gl->menu->sp[k].r_text_sp[i].h);
		gl->menu->sp[k].r_text_sp[i].x = x;
		gl->menu->sp[k].r_text_sp[i].y = y + step;
		step += 30;
	}
}

void	fill_data_cyl(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	get_data_from_cyl(gl, k);
	i = -1;
	step = 100;
	while (++i < 11)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->cyl[k].info[i], (SDL_Color)COLOR_BLUE);
		gl->menu->cyl[k].t_text_cyl[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->cyl[k].t_text_cyl[i], NULL, NULL,
			&gl->menu->cyl[k].r_text_cyl[i].w,
			&gl->menu->cyl[k].r_text_cyl[i].h);
		gl->menu->cyl[k].r_text_cyl[i].x = x;
		gl->menu->cyl[k].r_text_cyl[i].y = y + step;
		step += 30;
	}
}

void	detection(t_arr *gl, t_ray *ray, t_current **cur, int ind)
{
	int i;

	i = -1;
	while (++i < gl->total)
		if (gl->all_obj[i]->intersect(gl, ray, gl->all_obj[i], cur[ind]->id))
			if (gl->t[cur[ind]->id] > 1e-4)
				set_distance(gl, cur[ind], gl->all_obj[i]);
}

void	render(t_arr *gl, t_current *cur, t_lsrc *src)
{
	t_vec	tmp;
	double	dist;

	tmp = mul(&cur->n, BIAS, 1);
	tmp = add(&cur->p, &tmp, 1);
	create_v(cur->bck->org, tmp.x, tmp.y, tmp.z);
	tmp = add(src->lgt, &cur->p, 2);
	dist = sqrt(dot(&tmp, &tmp));
	create_v(cur->bck->dir, tmp.x, tmp.y, tmp.z);
	norm(cur->bck->dir);
	src->lamb = AMBI;
	src->fong = 0;
	if (!(inshadow(gl, gl->all_obj, cur, dist)))
	{
		light(cur, src);
		src->lamb /= gl->lights;
		if (src->lamb < 0)
			src->lamb = 0;
		if (src->lamb > 1.0)
			src->lamb = 1.0;
	}
}
