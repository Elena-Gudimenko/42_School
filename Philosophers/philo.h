/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:53:13 by elvictor          #+#    #+#             */
/*   Updated: 2025/07/02 19:14:53 by elvictor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

# define RST    "\033[0m"
# define RED    "\033[1;31m"
# define G      "\033[1;32m"
# define Y      "\033[1;33m"
# define B      "\033[1;34m"
# define M      "\033[1;35m"
# define C      "\033[1;36m"
# define W      "\033[1;37m"

typedef pthread_mutex_t t_mtx;
typedef struct s_table t_table;

typedef struct  s_forkerrors checking, filling table
{
    t_mtx       fork;
    int         fork_id;
}                   t_fork;

typedef struct  s_philo
{
    int         id;
    long        meals_counter;
    bool        full;
    long        last_meal_time;
    t_fork      *left_fork;
    t_fork      *right_fork;
    pthread_t   thread_id;
    t_table     *table;
}                   t_philo;

struct  s_table
{
    long        philo_nbr;
    long        time_to_die;
    long        time_to_eat;
    long        time_to_sleep;
    long        nbr_limit_meals;
    long        start_simulation;
    bool        end_simulation; //philo dies or all philos full
    t_fork      *forks; // array fo forks
    t_philo     *philos;
};

void    error_exit(const char *error);