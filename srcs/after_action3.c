/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_action3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:02:56 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 21:04:03 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	checking_flags_s2(t_arr *gl)
{
	if (gl->menu->flag.help % 2 == 1)
	{
		SDL_RenderClear(gl->sdl->renderer);
		SDL_RenderCopy(gl->sdl->renderer,
			gl->menu->texture_img[9],
			NULL, &gl->menu->rect_img[9]);
		SDL_RenderPresent(gl->sdl->renderer);
	}
}
