/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:57:55 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:49:10 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	count_tor(t_arr *gl)
{
	int	tor;
	int i;
	int k;

	i = -1;
	tor = 0;
	while (++i < gl->total)
		if (gl->all_obj[i]->flag == 5)
			tor++;
	gl->menu->cnt_tor = tor;
	if (tor > 0)
		gl->menu->tor = (t_tor_menu *)malloc(sizeof(t_tor_menu) * tor);
	k = -1;
	i = -1;
	if (tor > 0)
		while (++i < gl->total)
			if (gl->all_obj[i]->flag == 5)
				gl->menu->tor[++k].index = i;
}

void	fill_names_tor(t_arr *gl)
{
	gl->menu->names_tor = (char **)malloc(sizeof(char *) * 11);
	gl->menu->names_tor[0] = "Center:";
	gl->menu->names_tor[1] = "Direct:";
	gl->menu->names_tor[2] = "Radius1:";
	gl->menu->names_tor[3] = "Radius2:";
	gl->menu->names_tor[4] = "Color:";
	gl->menu->names_tor[5] = "Diffuse:";
	gl->menu->names_tor[6] = "Specular:";
	gl->menu->names_tor[7] = "Reflection:";
	gl->menu->names_tor[8] = "Refraction:";
	gl->menu->names_tor[9] = "Index:";
}

void	fill_tor(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	i = -1;
	step = 100;
	while (++i < 10)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->names_tor[i], (SDL_Color)COLOR_BLACK);
		gl->menu->tor[k].texture_text_tor[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->tor[k].texture_text_tor[i], NULL, NULL,
			&gl->menu->tor[k].rect_text_tor[i].w,
			&gl->menu->tor[k].rect_text_tor[i].h);
		gl->menu->tor[k].rect_text_tor[i].x = x;
		gl->menu->tor[k].rect_text_tor[i].y = y + step;
		step += 30;
	}
}

void	get_data_from_tor(t_arr *gl, int k)
{
	gl->menu->tor[k].info = (char **)malloc(sizeof(char *) * 10);
	info_to_str_tor(gl, k, 0);
	info_to_str_tor(gl, k, 1);
	info_to_str_tor(gl, k, 2);
	info_to_str_tor(gl, k, 3);
	info_to_str_tor(gl, k, 4);
	info_to_str_tor(gl, k, 5);
	info_to_str_tor(gl, k, 6);
	info_to_str_tor(gl, k, 7);
	info_to_str_tor(gl, k, 8);
	info_to_str_tor(gl, k, 9);
}
