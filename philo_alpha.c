/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:25:12 by tkomeno           #+#    #+#             */
/*   Updated: 2023/04/18 17:33:22 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PHILO_NUM 5

typedef enum philo_status
{
	THINKING,
	HUNGRY,
	EATING
} philo_status;

typedef struct philo
{
	philo_status state;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
} philo;

philo philosophers[PHILO_NUM];

pthread_mutex_t print_mutex;

void init()
{
	for (int i = 0; i < PHILO_NUM; i++)
	{
		philosophers[i].state = THINKING;
		pthread_mutex_init(&philosophers[i].mutex, NULL);
		pthread_cond_init(&philosophers[i].cond, NULL);
	}
	pthread_mutex_init(&print_mutex, NULL);
}

void cleanup()
{
	for (int i = 0; i < PHILO_NUM; i++)
	{
		pthread_mutex_destroy(&philosophers[i].mutex);
		pthread_cond_destroy(&philosophers[i].cond);
	}
	pthread_mutex_destroy(&print_mutex);
}
