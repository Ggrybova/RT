/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conus_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:55:05 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 11:56:59 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	count_conus(t_arr *gl)
{
	int	con;
	int	i;
	int	k;

	i = -1;
	con = 0;
	while (++i < gl->total)
		if (gl->all_obj[i]->flag == 4)
			con++;
	gl->menu->cnt_con = con;
	if (con > 0)
		gl->menu->con = (t_con_menu *)malloc(sizeof(t_con_menu) * con);
	k = -1;
	i = -1;
	if (con > 0)
		while (++i < gl->total)
			if (gl->all_obj[i]->flag == 4)
				gl->menu->con[++k].index = i;
}

void	fill_names_con(t_arr *gl)
{
	gl->menu->names_con = (char **)malloc(sizeof(char *) * 11);
	gl->menu->names_con[0] = "Center:";
	gl->menu->names_con[1] = "Direct:";
	gl->menu->names_con[2] = "Angle:";
	gl->menu->names_con[3] = "Height:";
	gl->menu->names_con[4] = "Caps:";
	gl->menu->names_con[5] = "Color:";
	gl->menu->names_con[6] = "Diffuse:";
	gl->menu->names_con[7] = "Specular:";
	gl->menu->names_con[8] = "Reflection:";
	gl->menu->names_con[9] = "Refraction:";
	gl->menu->names_con[10] = "Index:";
}

void	fill_con(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	i = -1;
	step = 100;
	while (++i < 11)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->names_con[i], (SDL_Color)COLOR_BLACK);
		gl->menu->con[k].texture_text_con[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer, gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->con[k].texture_text_con[i], NULL, NULL,
			&gl->menu->con[k].rect_text_con[i].w,
			&gl->menu->con[k].rect_text_con[i].h);
		gl->menu->con[k].rect_text_con[i].x = x;
		gl->menu->con[k].rect_text_con[i].y = y + step;
		step += 30;
	}
}

void	get_data_from_con(t_arr *gl, int k)
{
	gl->menu->con[k].info = (char **)malloc(sizeof(char *) * 11);
	info_to_str_con(gl, k, 0);
	info_to_str_con(gl, k, 1);
	info_to_str_con(gl, k, 2);
	info_to_str_con(gl, k, 3);
	info_to_str_con(gl, k, 4);
	info_to_str_con(gl, k, 5);
	info_to_str_con(gl, k, 6);
	info_to_str_con(gl, k, 7);
	info_to_str_con(gl, k, 8);
	info_to_str_con(gl, k, 9);
	info_to_str_con(gl, k, 10);
	info_to_str_con(gl, k, 11);
}
