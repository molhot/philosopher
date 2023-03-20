/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:22:22 by user              #+#    #+#             */
/*   Updated: 2023/03/21 03:29:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	bool	init_forks(t_allinfo *val)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i != val->philo_num)
	{
		if (pthread_mutex_init(&((val->forks)[i]), NULL) == false)
		{
			if (i != 0)
			while (j != i)
			{
				pthread_mutex_destroy(&((val->forks)[j]));
				j++;
			}
			return (mutex_initmiss());
		}
		i++;
	}
	return (true);
}

static	bool	ready_philoinfo(t_allinfo *val, char **argv, int argc)
{
	val->philo_num = (size_t)ft_atoi(argv[1]);
	val->die_tm = (size_t)ft_atoi(argv[2]);
	val->eat_tm = (size_t)ft_atoi(argv[3]);
	val->sleep_tm = (size_t)ft_atoi(argv[4]);
	val->dieornot = false;
	val->eat_count = 0;
	if (argc == 6)
		val->eatlimit = ft_atoi(argv[5]);
	else
		val->eatlimit = -1;
	if (pthread_mutex_init(&(val->writelock), NULL) == false)
		return (mutex_initmiss());
	val->forks = malloc(sizeof(pthread_mutex_t) * val->philo_num);
	if (val->forks == NULL)
		return (malloc_error());
	if (init_forks(val) == false)
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
    t_allinfo	all;
    
    if (arg_check(argc, argv) == false)
        return (1);
	if (ready_philoinfo(&all, argv, argc) == false)
		return (1);
	if (ready_samephilo(&all) == false)
		return (1);
	
}