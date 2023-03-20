#ifndef Philo_H
# define Philo_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philo_info	t_philo;

typedef struct all_info {
	pthread_mutex_t	*forks;
    pthread_t		checker;
	t_philo			*philoinfo;
	size_t			philo_num;
	size_t			eat_tm;
	size_t			sleep_tm;
	size_t			die_tm;
	int				eatlimit;
	bool			dieornot;
}	t_allinfo;

typedef struct philo_info{
    pthread_t		philo_thread;
	size_t			number_of_philo;
	size_t			how_eated;
	size_t			l_f;
    size_t			r_f;
	long long		philo_livedstart;
	bool			correctend;
	t_allinfo		*all_info;
}t_philo;

int		main(int argc, char **argv);
//1 argcheck//
bool	arg_check(int argnum, char **arg);

//utils------------------------------------//
bool	arg_check(int argnum, char **arg);

#endif