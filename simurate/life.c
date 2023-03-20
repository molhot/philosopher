/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:57:23 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:34:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philolife_life(void *info_t)
{
	t_philo		*info;

	info = (t_philo *)info_t;
	info->philo_livedstart = getnowtime();
	while (1)
	{
		if (eat_drop(info, info->l_f, info->r_f) == false)
			return (NULL);
		if (info->all_info->eatlimit <= (int)info->how_eated)
			break ;
		if (sleeping(info) == false)
			return (NULL);
		if (think(info) == false)
			return (NULL);
	}
	info->correctend = true;
	info->all_info->eat_count = info->all_info->eat_count + 1;
	return (NULL);
}

void	*philolife_life_ult(void *info_t)
{
	t_philo	*info;

	info = (t_philo *)info_t;
	livestart_ch(info);
	while (1)
	{
		if (eat_drop(info, info->l_f, info->r_f) == false)
			return (NULL);
		if (sleeping(info) == false)
			return (NULL);
		if (think(info) == false)
			return (NULL);
	}
	return (NULL);
}
