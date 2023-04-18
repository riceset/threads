/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concurrency.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:45:43 by tkomeno           #+#    #+#             */
/*   Updated: 2023/04/18 17:10:18 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func1(void *arg)
{
	printf("From thread1!\n");
	return (NULL);
}

void *thread_func2(void *arg)
{
	printf("From thread2!\n");
	return (NULL);
}

int main(void)
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, thread_func1, NULL);
	pthread_create(&thread2, NULL, thread_func2, NULL);

	//waits for both threads to finish.
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return (0);
}
