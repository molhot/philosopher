/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:37:02 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:40:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	unlock_onefork(t_philo *info, int *f)
{
	pthread_mutex_unlock(&info->all_info->forks[*f]);
}

bool	error_unlockonefork(t_philo *info, int *f)
{
	unlock_onefork(info, f);
	return (false);
}

void	unlock_allfork(t_philo *info, int *l_f, int *r_f)
{
	pthread_mutex_unlock(&info->all_info->forks[*r_f]);
	pthread_mutex_unlock(&info->all_info->forks[*l_f]);
}

bool	error_unlokallfork(t_philo *info, int *l_f, int *r_f)
{
	unlock_allfork(info, l_f, r_f);
	return (false);
}
