/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:58:41 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 10:05:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void);

void enqueue(struct s_queue *queue, void *content);

void *dequeue(struct s_queue *queue);

void *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);

#include <stdio.h>

int main()
{
	struct s_queue *n;

	n = init();
	printf("is the empty queue empty? %s\n", isEmpty(n) == 1 ? "yes" : "no");

	enqueue(n, (void*)"hello");
	enqueue(n, (void*)" world");
	printf("is the queue empty? %s\n", isEmpty(n) == 1 ? "yes" : "no");

	printf("value in top node: %s\n", (char*)dequeue(n));
	printf("is the empty queue empty? %s\n", isEmpty(n) == 1 ? "yes" : "no");
	printf("value in top node: %s\n", (char*)dequeue(n));

	//should be empty
	printf("is the empty queue empty? %s\n", isEmpty(n) == 1 ? "yes" : "no");

	return 0;
}
