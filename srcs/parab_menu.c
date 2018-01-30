/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parab_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:10:18 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:49:12 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	count_par(t_arr *gl)
{
	int par;
	int i;
	int k;

	i = -1;
	par = 0;
	while (++i < gl->total)
		if (gl->all_obj[i]->flag == 7)
			par++;
	gl->menu->cnt_par = par;
	if (par > 0)
		gl->menu->par = (t_par_menu *)malloc(sizeof(t_par_menu) * par);
	k = -1;
	i = -1;
	if (par > 0)
		while (++i < gl->total)
			if (gl->all_obj[i]->flag == 7)
				gl->menu->par[++k].index = i;
}

void	fill_names_par(t_arr *gl)
{
	gl->menu->names_par = (char **)malloc(sizeof(char *) * 11);
	gl->menu->names_par[0] = "Center:";
	gl->menu->names_par[1] = "Direct:";
	gl->menu->names_par[2] = "Radius:";
	gl->menu->names_par[3] = "Caps:";
	gl->menu->names_par[4] = "Angle:";
	gl->menu->names_par[5] = "Height:";
	gl->menu->names_par[6] = "Color:";
	gl->menu->names_par[7] = "Diffuse:";
	gl->menu->names_par[8] = "Specular:";
	gl->menu->names_par[9] = "Reflection:";
	gl->menu->names_par[10] = "Refraction:";
	gl->menu->names_par[11] = "Index:";
}

void	fill_par(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	i = -1;
	step = 100;
	while (++i < 11)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->names_par[i], (SDL_Color)COLOR_BLACK);
		gl->menu->par[k].texture_text_par[i] =
			SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->par[k].texture_text_par[i], NULL, NULL,
			&gl->menu->par[k].rect_text_par[i].w,
			&gl->menu->par[k].rect_text_par[i].h);
		gl->menu->par[k].rect_text_par[i].x = x;
		gl->menu->par[k].rect_text_par[i].y = y + step;
		step += 30;
	}
}

void	get_data_from_par(t_arr *gl, int k)
{
	gl->menu->par[k].info = (char **)malloc(sizeof(char *) * 11);
	info_to_str_par(gl, k, 0);
	info_to_str_par(gl, k, 1);
	info_to_str_par(gl, k, 2);
	info_to_str_par(gl, k, 3);
	info_to_str_par(gl, k, 4);
	info_to_str_par(gl, k, 5);
	info_to_str_par(gl, k, 6);
	info_to_str_par(gl, k, 7);
	info_to_str_par(gl, k, 8);
	info_to_str_par(gl, k, 9);
	info_to_str_par(gl, k, 10);
	info_to_str_par(gl, k, 11);
}
