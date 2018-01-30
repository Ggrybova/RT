/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 06:42:30 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:49:13 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	count_dsk(t_arr *gl)
{
	int	dsk;
	int	i;
	int	k;

	i = -1;
	dsk = 0;
	while (++i < gl->total)
		if (gl->all_obj[i]->flag == 6)
			dsk++;
	gl->menu->cnt_dsk = dsk;
	if (dsk > 0)
		gl->menu->dsk = (t_dsk_menu *)malloc(sizeof(t_dsk_menu) * dsk);
	k = -1;
	i = -1;
	if (dsk > 0)
		while (++i < gl->total)
			if (gl->all_obj[i]->flag == 6)
				gl->menu->dsk[++k].index = i;
}

void	fill_names_dsk(t_arr *gl)
{
	gl->menu->names_dsk = (char **)malloc(sizeof(char *) * 9);
	gl->menu->names_dsk[0] = "Center:";
	gl->menu->names_dsk[1] = "Direct:";
	gl->menu->names_dsk[2] = "Radius:";
	gl->menu->names_dsk[3] = "Color:";
	gl->menu->names_dsk[4] = "Diffuse:";
	gl->menu->names_dsk[5] = "Specular:";
	gl->menu->names_dsk[6] = "Reflection:";
	gl->menu->names_dsk[7] = "Refraction:";
	gl->menu->names_dsk[8] = "Index:";
}

void	fill_dsk(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	i = -1;
	step = 100;
	while (++i < 9)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->names_dsk[i], (SDL_Color)COLOR_BLACK);
		gl->menu->dsk[k].texture_text_dsk[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->dsk[k].texture_text_dsk[i], NULL, NULL,
			&gl->menu->dsk[k].rect_text_dsk[i].w,
			&gl->menu->dsk[k].rect_text_dsk[i].h);
		gl->menu->dsk[k].rect_text_dsk[i].x = x;
		gl->menu->dsk[k].rect_text_dsk[i].y = y + step;
		step += 30;
	}
}

void	get_data_from_dsk(t_arr *gl, int k)
{
	gl->menu->dsk[k].info = (char **)malloc(sizeof(char *) * 9);
	info_to_str_dsk(gl, k, 0);
	info_to_str_dsk(gl, k, 1);
	info_to_str_dsk(gl, k, 2);
	info_to_str_dsk(gl, k, 3);
	info_to_str_dsk(gl, k, 4);
	info_to_str_dsk(gl, k, 5);
	info_to_str_dsk(gl, k, 6);
	info_to_str_dsk(gl, k, 7);
	info_to_str_dsk(gl, k, 8);
}
