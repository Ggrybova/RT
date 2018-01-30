/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:20:42 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 13:44:14 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	fill_tab_names(t_arr *gl)
{
	gl->menu->tab_names = (char **)malloc(sizeof(char *) * 8);
	gl->menu->tab_names[0] = "Sphere";
	gl->menu->tab_names[1] = "Cylinder";
	gl->menu->tab_names[2] = "Conus";
	gl->menu->tab_names[3] = "Torus";
	gl->menu->tab_names[4] = "Parabaloid";
	gl->menu->tab_names[5] = "Disk";
	gl->menu->tab_names[6] = "Camera";
	gl->menu->tab_names[7] = "Light";
}

void	fill_data_con(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	get_data_from_con(gl, k);
	i = -1;
	step = 100;
	while (++i < 11)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->con[k].info[i], (SDL_Color)COLOR_BLUE);
		gl->menu->con[k].t_text_con[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->con[k].t_text_con[i], NULL, NULL,
			&gl->menu->con[k].r_text_con[i].w,
			&gl->menu->con[k].r_text_con[i].h);
		gl->menu->con[k].r_text_con[i].x = x;
		gl->menu->con[k].r_text_con[i].y = y + step;
		step += 30;
	}
}

void	fill_data_tor(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	get_data_from_tor(gl, k);
	i = -1;
	step = 100;
	while (++i < 10)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->tor[k].info[i], (SDL_Color)COLOR_BLUE);
		gl->menu->tor[k].t_text_tor[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->tor[k].t_text_tor[i], NULL, NULL,
			&gl->menu->tor[k].r_text_tor[i].w,
			&gl->menu->tor[k].r_text_tor[i].h);
		gl->menu->tor[k].r_text_tor[i].x = x;
		gl->menu->tor[k].r_text_tor[i].y = y + step;
		step += 30;
	}
}

void	fill_data_par(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	get_data_from_par(gl, k);
	i = -1;
	step = 100;
	while (++i < 10)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->par[k].info[i], (SDL_Color)COLOR_BLUE);
		gl->menu->par[k].t_text_par[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->par[k].t_text_par[i], NULL, NULL,
			&gl->menu->par[k].r_text_par[i].w,
			&gl->menu->par[k].r_text_par[i].h);
		gl->menu->par[k].r_text_par[i].x = x;
		gl->menu->par[k].r_text_par[i].y = y + step;
		step += 30;
	}
}

void	fill_data_dsk(t_arr *gl, int k, int x, int y)
{
	int			i;
	int			step;

	get_data_from_dsk(gl, k);
	i = -1;
	step = 100;
	while (++i < 9)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font_info,
			gl->menu->dsk[k].info[i], (SDL_Color)COLOR_BLUE);
		gl->menu->dsk[k].t_text_dsk[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer,
			gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->dsk[k].t_text_dsk[i], NULL, NULL,
			&gl->menu->dsk[k].r_text_dsk[i].w,
			&gl->menu->dsk[k].r_text_dsk[i].h);
		gl->menu->dsk[k].r_text_dsk[i].x = x;
		gl->menu->dsk[k].r_text_dsk[i].y = y + step;
		step += 30;
	}
}
