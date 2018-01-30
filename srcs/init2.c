/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:53:01 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:06:16 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	init_font2(t_arr *gl, int i)
{
	while (++i < 8)
	{
		gl->menu->surface = TTF_RenderText_Solid(gl->menu->font,
			gl->menu->tab_names[i], (SDL_Color)COLOR_BLUE);
		gl->menu->texture_text[i] =
		SDL_CreateTextureFromSurface(gl->sdl->renderer, gl->menu->surface);
		SDL_FreeSurface(gl->menu->surface);
		SDL_QueryTexture(gl->menu->texture_text[i], NULL, NULL,
			&gl->menu->rect_text[i].w, &gl->menu->rect_text[i].h);
		gl->menu->rect_text[i].x = 240;
		gl->menu->rect_text[i].y = 30;
	}
}

void		init_font(t_arr *gl)
{
	char		*f1;
	char		*f2;

	if (TTF_Init() == -1)
		ft_error(3);
	f1 = "fonts/SansPosterBold.ttf";
	f2 = "fonts/Prototype.ttf";
	if (!(gl->menu->font = TTF_OpenFont(f1, 60)))
		ft_error(4);
	if (!(gl->menu->font_info = TTF_OpenFont(f2, 24)))
		ft_error(5);
	fill_tab_names(gl);
	init_font2(gl, -1);
}

void		init_flags_menu(t_arr *gl)
{
	gl->running = 1;
	gl->menu->flag.team = 1;
	gl->menu->flag.menu = 0;
	gl->menu->flag.d = 0;
	gl->menu->flag.help = 0;
	gl->menu->flag.pos = 1;
}
