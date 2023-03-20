/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:57:20 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:51:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	philo_deathistrue(size_t philo_num, t_allinfo *info)
{
	if ((getnowtime() - info->philoinfo[philo_num].philo_livedstart) > info->die_tm)
	{
		if (print_action(&(info->philoinfo[philo_num]), "died") == false)
			return (false);
		info->dieornot = true;
		return (false);
	}
	return (true);
}

void	*philo_checker(void *info_i)
{
	size_t		philo_num;
	t_allinfo	*info;

	philo_num = 0;
	info = (t_allinfo *)info_i;
	while (1)
	{
		if (info->eat_count == info->philo_num)
			return (NULL);
        if (info->philoinfo[philo_num].correctend == false)
			if (philo_deathistrue(philo_num, info) == false)
				return (NULL);
		philo_num++;
		if ((int)philo_num == info->philo_num)
			philo_num = 0;
		usleep(300);
	}
	return (NULL);
}
