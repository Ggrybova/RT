/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:22:20 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:49:11 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	count_sphere(t_arr *gl)
{
	int	sp;
	int	i;
	int	k;

	i = -1;
	sp = 0;
	while (++i < gl->total)
		if (gl->all_obj[i]->flag == 2)
			sp++;
	gl->menu->cnt_sp = sp;
	if (sp > 0)
		gl->menu->sp = (t_sp_menu *)malloc(sizeof(t_sp_menu) * sp);
	k = -1;
	i = -1;
	if (sp > 0)
		while (++i < gl->total)
			if (gl->all_obj[i]->flag == 2)
				gl->menu->sp[++k].index = i;
}

void	fill_names_sp(t_arr *gl)
{
	gl->menu->names_sp = (char **)malloc(sizeof(char *) * 8);
	gl->menu->names_sp[0] = "Center:";
	gl->menu->names_sp[1] = "Radius:";
	gl->menu->names_sp[2] = "Color:";
	gl->menu->names_sp[3] = "Diffuse:";
	gl->menu->names_sp[4] = "Specular:";
	gl->menu->names_sp[5] = "Reflection:";
	gl->menu->names_sp[6] = "Refraction:";
	gl->menu->names_sp[7] = "Index:";
}

void	fill_sp(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	i = -1;
	step = 100;
	while (++i < 8)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->names_sp[i], (SDL_Color)COLOR_BLACK);
		gl->menu->sp[k].texture_text_sp[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->sp[k].texture_text_sp[i], NULL, NULL,
			&gl->menu->sp[k].rect_text_sp[i].w,
			&gl->menu->sp[k].rect_text_sp[i].h);
		gl->menu->sp[k].rect_text_sp[i].x = x;
		gl->menu->sp[k].rect_text_sp[i].y = y + step;
		step += 30;
	}
}

void	get_data_from_sp(t_arr *gl, int k)
{
	gl->menu->sp[k].info = (char **)malloc(sizeof(char *) * 7);
	info_to_str_sp(gl, k, 0);
	info_to_str_sp(gl, k, 1);
	info_to_str_sp(gl, k, 2);
	info_to_str_sp(gl, k, 3);
	info_to_str_sp(gl, k, 4);
	info_to_str_sp(gl, k, 5);
	info_to_str_sp(gl, k, 6);
	info_to_str_sp(gl, k, 7);
}
