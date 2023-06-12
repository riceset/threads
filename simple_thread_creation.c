/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:46:33 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/12 15:53:05 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef pthread_t thread;

void *my_turn(void *arg)
{
	while (true)
	{
		sleep(2);
		printf("my turn!\n");
	}
}

void your_turn(void)
{
	while (true)
	{
		sleep(2);
		printf("your turn!\n");
	}
}

int main(void)
{
	thread new_thread;

	pthread_create(&new_thread, NULL, my_turn, NULL);

	your_turn();

	return (0);
}
