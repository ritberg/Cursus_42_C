/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <mmakarov@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:13:06 by mmakarov          #+#    #+#             */
/*   Updated: 2023/07/03 12:07:35 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

# define ARGS_NUMBER 		1
# define NOT_DIGIT			2
# define N_PHILOS			3
# define BIGGER_THAN_INTMAX	-1
# define NO_FIFTH_ARG		-2

# define MALLOC_ERROR	"malloc error!\n"
# define PTHREAD_ERROR	"pthread error!\n"

# define FORKS		"has taken a fork\n"
# define EATING		"is eating\n"
# define SLEEPING	"is sleeping\n"
# define THINKING	"is thinking\n"
# define DIED		"died\n"

typedef struct s_philo
{
	pthread_t		p_thread;
	int				p_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	time_t			last_meal_time;
	pthread_mutex_t	meal_lock;
	int				meal_finished;
	int				times_ate;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	pthread_t		checker_thread;
	time_t			start_time;
	int				n_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				times_must_eat;
	int				dead;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	lock;
	pthread_mutex_t	stop_lock;
}	t_data;

/****************************
          utils.c
****************************/
time_t	get_current_time(void);
int		ft_atoi(char *str);
int		is_digit(char *str);
void	ft_usleep(int ms);

/****************************
      structures_init.c
****************************/
t_data	*init_data_structure(int argc, char **argv);
t_philo	*init_philo_structure(t_data *data);

/****************************
      errors_frees.c
****************************/
void	mutex_destroy(t_data *data);
void	free_structures(t_data *data);
int		error_message(int flag);

/****************************
       philos_init.c
****************************/
int		init_philos_threads(t_data *data);
void	*p_routine(void *ptr);

#endif
