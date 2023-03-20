/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nolimit_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:06:04 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:20:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	bool	checker_start(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	if (pthread_create(&info->checker, NULL, \
	&philo_checker, (void *)info) != 0)
		return (false);
	usleep(100);
	while ((int)philo_num != info->philo_num)
	{
		pthread_join((info->philoinfo[philo_num]).philo_thread, NULL);
		philo_num++;
	}
	if (pthread_join(info->checker, NULL) != 0)
		return (false);
	return (true);
}

bool	start_philolife(t_philo *subject)
{
	if (pthread_create(&(subject->philo_thread), NULL, \
	&philolife_life_ult, (void *)(subject)) != 0)
		return (false);
	return (true);
}

bool	phlife(t_allinfo *info, size_t *philo_num)
{
	if ((*philo_num) % 2 == 1 && *philo_num == 1)
		usleep(200);
	if (start_philolife(&((info->philoinfo)[*philo_num])) == false)
		return (false);
	*philo_num = *philo_num + 2;
	return (true);
}

bool	start_thread_u(t_allinfo *info)
{
	size_t	philo_num;

	philo_num = 0;
	while (philo_num < info->philo_num)
		if (phlife(info, &philo_num) == false)
			return (false);
	philo_num = 1;
	while (philo_num < info->philo_num)
		if (phlife(info, &philo_num) == false)
			return (false);
	usleep(200);
	if (checker_start(info) == false)
		return (false);
	return (true);
}
