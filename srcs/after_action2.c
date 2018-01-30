/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_action2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:51:38 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 13:36:21 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	change_menu_tabs5(t_arr *gl, int i, int j)
{
	if (gl->menu->flag.pos == 6)
	{
		while (++i < gl->menu->cnt_dsk && i < 4)
		{
			j = -1;
			while (++j < 9)
			{
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->dsk[i].texture_text_dsk[j],
					NULL, &gl->menu->dsk[i].rect_text_dsk[j]);
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->dsk[i].t_text_dsk[j],
					NULL, &gl->menu->dsk[i].r_text_dsk[j]);
			}
		}
	}
}

static void	change_menu_tabs4(t_arr *gl, int i, int j)
{
	if (gl->menu->flag.pos == 5)
	{
		while (++i < gl->menu->cnt_par && i < 4)
		{
			j = -1;
			while (++j < 10)
			{
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->par[i].texture_text_par[j],
					NULL, &gl->menu->par[i].rect_text_par[j]);
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->par[i].t_text_par[j],
					NULL, &gl->menu->par[i].r_text_par[j]);
			}
		}
	}
	else
		change_menu_tabs5(gl, -1, -1);
}

void		change_menu_tabs3(t_arr *gl, int i, int j)
{
	if (gl->menu->flag.pos == 4)
	{
		while (++i < gl->menu->cnt_tor && i < 4)
		{
			j = -1;
			while (++j < 10)
			{
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->tor[i].texture_text_tor[j],
					NULL, &gl->menu->tor[i].rect_text_tor[j]);
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->tor[i].t_text_tor[j],
					NULL, &gl->menu->tor[i].r_text_tor[j]);
			}
		}
	}
	else
		change_menu_tabs4(gl, -1, -1);
}
