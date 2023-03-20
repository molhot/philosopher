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
	pthread_mutex_t	writelock;
    pthread_t		checker;
	t_philo			*philoinfo;
	size_t			philo_num;
	size_t			eat_tm;
	size_t			sleep_tm;
	size_t			die_tm;
	size_t			eat_count;
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

int			main(int argc, char **argv);
//1 argcheck//
bool		arg_check(int argnum, char **arg);
//2 ready philoinfo//
bool		ready_samephilo(t_allinfo *info);
//3 start thread//
bool		start_thread(t_allinfo *info);
bool		start_thread_u(t_allinfo *info);

//life//
void		*philolife_life(void *info_t);
void		*philolife_life_ult(void *info_t);
//checker//
void		*philo_checker(void *info_i);
//unlockfork
void		unlock_onefork(t_philo *info, int *f);
bool		error_unlockonefork(t_philo *info, int *f);
void		unlock_allfork(t_philo *info, int *l_f, int *r_f);
bool		error_unlokallfork(t_philo *info, int *l_f, int *r_f);

//utils------------------------------------//
bool		argis_null(void);
bool		argnum_error(void);
bool		argval_error(void);
bool		argzero_error(void);
bool		malloc_error(void);
bool		mutex_initmiss(void);
int			ft_atoi(const char *str);
long long	getnowtime(void);

#endif