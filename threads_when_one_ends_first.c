/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_when_one_ends_first.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:46:33 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/12 16:02:42 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void *my_turn(void *arg)
{
	for (int i = 0; i < 8; i++)
	{
		sleep(2);
		printf("\e[0;31mTurn %d\n\e[0;00m", i);
	}

	return (NULL);
}

void your_turn(void)
{
	for (int i = 0; i < 5; i++)
	{
		sleep(2);
		printf("\e[0;32mTurn %d\n\e[0;00m", i);
	}
}

int main(void)
{
	pthread_t new_thread;

	pthread_create(&new_thread, NULL, my_turn, NULL);

	your_turn();

	pthread_join(new_thread, NULL);

	return (0);
}
