/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_args_to_a_thread.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:08:09 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/12 16:21:31 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

void *my_turn(void *arg)
{
	int *n;

	n = (int *)malloc(sizeof(int));
	*n = 42;

	if (!n)
		return (NULL);

	for (int i = 0; i < 8; i++)
	{
		sleep(2);
		printf("\e[0;31mTurn %d and n = %d\n\e[0;00m", i, *n);
		(*n)++;
	}

	return (n);
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
	int *n;

	pthread_create(&new_thread, NULL, my_turn, &n);

	your_turn();

	pthread_join(new_thread, (void *)&n);

	printf("done! returned: %d\n", *n);

	return (0);
}
