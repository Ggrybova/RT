/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:46:06 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 12:48:35 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	count_cylinder(t_arr *gl)
{
	int	cyl;
	int	i;
	int	k;

	i = -1;
	cyl = 0;
	while (++i < gl->total)
		if (gl->all_obj[i]->flag == 3)
			cyl++;
	gl->menu->cnt_cyl = cyl;
	if (cyl > 0)
		gl->menu->cyl = (t_cyl_menu *)malloc(sizeof(t_cyl_menu) * cyl);
	k = -1;
	i = -1;
	if (cyl > 0)
		while (++i < gl->total)
			if (gl->all_obj[i]->flag == 3)
				gl->menu->cyl[++k].index = i;
}

void	fill_names_cyl(t_arr *gl)
{
	gl->menu->names_cyl = (char **)malloc(sizeof(char *) * 11);
	gl->menu->names_cyl[0] = "Center:";
	gl->menu->names_cyl[1] = "Direct:";
	gl->menu->names_cyl[2] = "Radius:";
	gl->menu->names_cyl[3] = "Height:";
	gl->menu->names_cyl[4] = "Caps:";
	gl->menu->names_cyl[5] = "Color:";
	gl->menu->names_cyl[6] = "Diffuse:";
	gl->menu->names_cyl[7] = "Specular:";
	gl->menu->names_cyl[8] = "Reflection:";
	gl->menu->names_cyl[9] = "Refraction:";
	gl->menu->names_cyl[10] = "Index:";
}

void	fill_cyl(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	i = -1;
	step = 100;
	while (++i < 11)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->names_cyl[i], (SDL_Color)COLOR_BLACK);
		gl->menu->cyl[k].texture_text_cyl[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->cyl[k].texture_text_cyl[i], NULL, NULL,
			&gl->menu->cyl[k].rect_text_cyl[i].w,
			&gl->menu->cyl[k].rect_text_cyl[i].h);
		gl->menu->cyl[k].rect_text_cyl[i].x = x;
		gl->menu->cyl[k].rect_text_cyl[i].y = y + step;
		step += 30;
	}
}

void	get_data_from_cyl(t_arr *gl, int k)
{
	gl->menu->cyl[k].info = (char **)malloc(sizeof(char *) * 11);
	info_to_str_cyl(gl, k, 0);
	info_to_str_cyl(gl, k, 1);
	info_to_str_cyl(gl, k, 2);
	info_to_str_cyl(gl, k, 3);
	info_to_str_cyl(gl, k, 4);
	info_to_str_cyl(gl, k, 5);
	info_to_str_cyl(gl, k, 6);
	info_to_str_cyl(gl, k, 7);
	info_to_str_cyl(gl, k, 8);
	info_to_str_cyl(gl, k, 9);
	info_to_str_cyl(gl, k, 10);
	info_to_str_cyl(gl, k, 11);
}
