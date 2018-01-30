/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:11:32 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:12:02 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		move_cam(t_arr *gl)
{
	if (gl->sdl->event.key.keysym.sym == SDLK_LEFT)
		gl->cam.x_t -= 10;
	else if (gl->sdl->event.key.keysym.sym == SDLK_RIGHT)
		gl->cam.x_t += 10;
	else if (gl->sdl->event.key.keysym.sym == SDLK_UP)
		gl->cam.y_t += 10;
	else if (gl->sdl->event.key.keysym.sym == SDLK_DOWN)
		gl->cam.y_t -= 10;
	mmul(gl);
	gl->menu->flag.d++;
}

void		keydown_actions3(t_arr *gl)
{
	if (gl->sdl->event.key.keysym.sym == SDLK_i &&
		gl->menu->flag.menu % 2 == 0 &&
		gl->menu->flag.team == 0)
	{
		gl->menu->flag.help++;
		if (gl->menu->flag.help % 2 == 0)
			gl->menu->flag.d++;
	}
	else if ((gl->sdl->event.key.keysym.sym == SDLK_LEFT ||
			gl->sdl->event.key.keysym.sym == SDLK_RIGHT ||
			gl->sdl->event.key.keysym.sym == SDLK_UP ||
			gl->sdl->event.key.keysym.sym == SDLK_DOWN) &&
			gl->menu->flag.team == 0 &&
			gl->menu->flag.help % 2 == 0 &&
			gl->menu->flag.menu % 2 == 0)
		move_cam(gl);
	else if (gl->sdl->event.key.keysym.sym == SDLK_m &&
		gl->menu->flag.team == 0 && gl->menu->flag.help % 2 == 0)
	{
		gl->menu->flag.menu++;
		if (gl->menu->flag.menu % 2 == 0)
			gl->menu->flag.d++;
	}
}

void		keydown_actions2(t_arr *gl)
{
	if (gl->sdl->event.key.keysym.sym == SDLK_1 &&
		gl->menu->flag.team == 0 &&
		gl->menu->flag.menu % 2 == 0 &&
		gl->menu->flag.help % 2 == 0)
	{
		gl->uv = -gl->uv;
		gl->grey = -1;
		gl->menu->flag.d++;
	}
	else if (gl->sdl->event.key.keysym.sym == SDLK_2 &&
		gl->menu->flag.team == 0 &&
		gl->menu->flag.menu % 2 == 0 &&
		gl->menu->flag.help % 2 == 0)
	{
		gl->grey = -gl->grey;
		gl->uv = -1;
		gl->menu->flag.d++;
	}
	else
		keydown_actions3(gl);
}
