/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 11:59:06 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:03:43 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	change_menu_tabs2(t_arr *gl, int i, int j)
{
	if (gl->menu->flag.pos == 3)
	{
		while (++i < gl->menu->cnt_con && i < 4)
		{
			j = -1;
			while (++j < 11)
			{
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->con[i].texture_text_con[j],
					NULL, &gl->menu->con[i].rect_text_con[j]);
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->con[i].t_text_con[j],
					NULL, &gl->menu->con[i].r_text_con[j]);
			}
		}
	}
	else
		change_menu_tabs3(gl, -1, -1);
}

static void	change_menu_tabs1(t_arr *gl, int i, int j)
{
	if (gl->menu->flag.pos == 2)
	{
		while (++i < gl->menu->cnt_cyl && i < 4)
		{
			j = -1;
			while (++j < 11)
			{
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->cyl[i].texture_text_cyl[j],
					NULL, &gl->menu->cyl[i].rect_text_cyl[j]);
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->cyl[i].t_text_cyl[j],
					NULL, &gl->menu->cyl[i].r_text_cyl[j]);
			}
		}
	}
	else
		change_menu_tabs2(gl, -1, -1);
}

static void	change_menu_tabs(t_arr *gl, int i, int j)
{
	if (gl->menu->flag.pos == 1)
	{
		while (++i < gl->menu->cnt_sp && i < 4)
		{
			j = -1;
			while (++j < 8)
			{
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->sp[i].texture_text_sp[j],
					NULL, &gl->menu->sp[i].rect_text_sp[j]);
				SDL_RenderCopy(gl->sdl->renderer,
					gl->menu->sp[i].t_text_sp[j],
					NULL, &gl->menu->sp[i].r_text_sp[j]);
			}
		}
	}
	else
		change_menu_tabs1(gl, -1, -1);
}

static void	checking_flags_s1(t_arr *gl)
{
	if (gl->menu->flag.team == 1)
	{
		SDL_RenderCopy(gl->sdl->renderer, gl->menu->texture_img[0],
			NULL, &gl->menu->rect_img[0]);
		SDL_RenderPresent(gl->sdl->renderer);
	}
	if (gl->menu->flag.menu % 2 == 1)
	{
		SDL_RenderClear(gl->sdl->renderer);
		SDL_RenderCopy(gl->sdl->renderer,
			gl->menu->texture_img[gl->menu->flag.pos],
			NULL, &gl->menu->rect_img[gl->menu->flag.pos]);
		SDL_RenderCopy(gl->sdl->renderer,
			gl->menu->texture_text[gl->menu->flag.pos - 1], NULL,
			&gl->menu->rect_text[gl->menu->flag.pos - 1]);
		change_menu_tabs(gl, -1, -1);
		SDL_RenderPresent(gl->sdl->renderer);
	}
	else
		checking_flags_s2(gl);
}

void		checking_flags(t_arr *gl, int y, int x)
{
	if (gl->menu->flag.d == 1)
	{
		SDL_RenderClear(gl->sdl->renderer);
		make_pthreads(gl);
		while (++y < W)
		{
			x = -1;
			while (++x < H)
			{
				SDL_SetRenderDrawColor(gl->sdl->renderer,
				(Uint8)gl->cl[y][x].r,
				(Uint8)gl->cl[y][x].g,
				(Uint8)gl->cl[y][x].b,
				255);
				SDL_RenderDrawPoint(gl->sdl->renderer, y, x);
				gl->cl[y][x].r = 0;
				gl->cl[y][x].g = 0;
				gl->cl[y][x].b = 0;
			}
		}
		SDL_RenderPresent(gl->sdl->renderer);
	}
	else
		checking_flags_s1(gl);
}
