/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:35:15 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:49:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static  void	eat_countup(t_philo *info)
{
	info->how_eated = info->how_eated + 1;
	info->philo_livedstart = getnowtime();
}

bool	eat_drop(t_philo *info, int l_f, int r_f)
{
	if (pthread_mutex_lock(&info->all_info->forks[l_f]) != 0)
		return (false);
	if (print_action(info, "has taken a fork") == false)
		return (error_unlockonefork(info, &l_f));
	if (l_f == r_f)
		return (error_unlockonefork(info, &l_f));
	if (pthread_mutex_lock(&info->all_info->forks[r_f]) != 0)
		return (error_unlockonefork(info, &l_f));
	if (print_action(info, "has taken a fork") == false)
		return (error_unlokallfork(info, &l_f, &r_f));
	if (print_action(info, "is eating") == false)
		return (error_unlokallfork(info, &l_f, &r_f));
	if (info->all_info->eat_tm > info->all_info->die_tm)
        return (error_unlokallfork(info, &l_f, &r_f));
	usleep(1000 * (long long)info->all_info->eat_tm);
	unlock_allfork(info, &l_f, &r_f);
	eat_countup(info);
	return (true);
}

bool	think(t_philo *info)
{
	bool	diecheck;

	if (print_action(info, "is thinking") == false)
		return (false);
	return (true);
}

bool	sleeping(t_philo *info)
{
	if (print_action(info, "is sleeping") == false)
		return (false);
	if (info->all_info->sleep_tm > info->all_info->die_tm)
		return (false);
	usleep(1000 * info->all_info->sleep_tm);
	if (info->number_of_philo == 2 && info->all_info->philo_num % 2 == 1)
		usleep(200);
	return (true);
}
