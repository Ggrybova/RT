/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:06:43 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:12:05 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	keydown_actions(t_arr *gl)
{
	if (gl->sdl->event.key.keysym.sym == SDLK_w)
		gl->cam.z_a -= 5;
	else if (gl->sdl->event.key.keysym.sym == SDLK_e)
		gl->cam.x_a += 5;
	else if (gl->sdl->event.key.keysym.sym == SDLK_d)
		gl->cam.y_a += 5;
	else if (gl->sdl->event.key.keysym.sym == SDLK_x)
		gl->cam.z_a += 5;
	else if (gl->sdl->event.key.keysym.sym == SDLK_z)
		gl->cam.x_a -= 5;
	else if (gl->sdl->event.key.keysym.sym == SDLK_a)
		gl->cam.y_a -= 5;
	else if (gl->sdl->event.key.keysym.sym == SDLK_KP_PLUS)
		gl->cam.z_t -= 10;
	else if (gl->sdl->event.key.keysym.sym == SDLK_KP_MINUS)
		gl->cam.z_t += 10;
	mmul(gl);
	gl->menu->flag.d++;
}

static void	keydown(t_arr *gl)
{
	if (gl->sdl->event.key.keysym.sym == SDLK_SPACE &&
		gl->menu->flag.help % 2 == 0 &&
		gl->menu->flag.menu % 2 == 0)
	{
		gl->menu->flag.team = 0;
		gl->menu->flag.d++;
	}
	else if ((gl->sdl->event.key.keysym.sym == SDLK_w ||
		gl->sdl->event.key.keysym.sym == SDLK_e ||
		gl->sdl->event.key.keysym.sym == SDLK_d ||
		gl->sdl->event.key.keysym.sym == SDLK_x ||
		gl->sdl->event.key.keysym.sym == SDLK_z ||
		gl->sdl->event.key.keysym.sym == SDLK_a ||
		gl->sdl->event.key.keysym.sym == SDLK_KP_PLUS ||
		gl->sdl->event.key.keysym.sym == SDLK_KP_MINUS) &&
		gl->menu->flag.team == 0 &&
		gl->menu->flag.help % 2 == 0 &&
		gl->menu->flag.menu % 2 == 0)
		keydown_actions(gl);
	else
		keydown_actions2(gl);
}

static void	mouse_action2(t_arr *gl)
{
	if (gl->sdl->event.motion.y > 135 && gl->sdl->event.motion.y < 245)
		gl->menu->flag.pos = 1;
	else if (gl->sdl->event.motion.y > 245 && gl->sdl->event.motion.y < 355)
		gl->menu->flag.pos = 2;
	else if (gl->sdl->event.motion.y > 355 && gl->sdl->event.motion.y < 465)
		gl->menu->flag.pos = 3;
	else if (gl->sdl->event.motion.y > 465 && gl->sdl->event.motion.y < 575)
		gl->menu->flag.pos = 4;
	else if (gl->sdl->event.motion.y > 575 && gl->sdl->event.motion.y < 685)
		gl->menu->flag.pos = 5;
	else if (gl->sdl->event.motion.y > 685 && gl->sdl->event.motion.y < 795)
		gl->menu->flag.pos = 6;
}

static void	mouse_action(t_arr *gl)
{
	if (gl->sdl->event.motion.x > 0 && gl->sdl->event.motion.x <= 145)
	{
		if (gl->sdl->event.motion.x < 75 &&
			gl->sdl->event.motion.y > 795 &&
			gl->sdl->event.motion.y < 870)
			gl->menu->flag.pos = 7;
		else if (gl->sdl->event.motion.x > 75 &&
			gl->sdl->event.motion.y > 795 &&
			gl->sdl->event.motion.y < 870)
			gl->menu->flag.pos = 8;
		else
			mouse_action2(gl);
	}
}

void		events(t_arr *gl)
{
	if (gl->sdl->event.type == SDL_QUIT ||
		(gl->sdl->event.type == SDL_KEYDOWN &&
		gl->sdl->event.key.keysym.sym == SDLK_ESCAPE))
		gl->running = 0;
	else if (gl->sdl->event.type == SDL_KEYDOWN &&
		gl->sdl->event.key.keysym.sym != SDLK_ESCAPE)
		keydown(gl);
	else if (gl->sdl->event.type == SDL_MOUSEBUTTONDOWN)
		mouse_action(gl);
}
