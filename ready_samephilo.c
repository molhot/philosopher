/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_samephilo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:24:57 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:02:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	destoroy_allmutex_e(t_allinfo *info)
{
	size_t	position;

	position = 0;
	pthread_mutex_destroy(&(info->writelock));
	while (position != info->philo_num)
	{
		pthread_mutex_destroy(&((info->forks)[position]));
		position++;
	}
	return (malloc_error());
}

static	void	insert_info_tophilo(int philonum, t_allinfo *info)
{
	((info->philoinfo)[philonum - 1]).r_f = philonum - 2;
	((info->philoinfo)[philonum - 1]).l_f = philonum - 1;
	((info->philoinfo)[philonum - 1]).how_eated = 0;
	((info->philoinfo)[philonum - 1]).number_of_philo = philonum;
	((info->philoinfo)[philonum - 1]).correctend = false;
	((info->philoinfo)[philonum - 1]).all_info = info;
}

bool	ready_samephilo(t_allinfo *info)
{
	size_t	p_n;

	info->philoinfo = malloc(sizeof(t_philo) * info->philo_num);
	if (info->philoinfo == NULL)
		return (destoroy_allmutex_e(info));
	p_n = 2;
	while (p_n != info->philo_num)
	{
		insert_info_tophilo(p_n, info);
		p_n++;
	}
	((info->philoinfo)[0]).r_f = 0;
	((info->philoinfo)[0]).l_f = info->philo_num - 1;
	((info->philoinfo)[0]).how_eated = 0;
	((info->philoinfo)[0]).number_of_philo = 1;
	((info->philoinfo)[0]).correctend = false;
	((info->philoinfo)[0]).all_info = info;
	return (true);
}
