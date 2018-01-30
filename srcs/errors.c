/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <vsydorch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:50:41 by vsydorch          #+#    #+#             */
/*   Updated: 2018/01/20 13:33:15 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_error(int flag)
{
	if (flag == 1)
	{
		ft_putstr("Not correct input file.\n");
		ft_putstr("Please,correct data and try again!\n");
	}
	else if (flag == 2)
		ft_putstr("Usage : ./RT <scene_file>.ini\n");
	else if (flag == 3)
		ft_putstr("Problem with TTF_Init()\n");
	else if (flag == 4)
		ft_putstr("Problem with init font1\n");
	else if (flag == 5)
		ft_putstr("Problem with init font2\n");
	else if (flag == 6)
		ft_putstr("Error init window\n");
	exit(0);
}
