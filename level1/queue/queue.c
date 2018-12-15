/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:20:52 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 09:48:48 by exam             ###   ########.fr       */
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


int isEmpty(struct s_queue *queue)
{
	if (queue->first)
		return 0;
	return 1;
}


struct s_queue *init(void)
{
	struct s_queue *ret;

	ret = malloc(sizeof(struct s_queue));
	ret->first = 0;
	ret->last = 0;
	return ret;
}

void enqueue(struct s_queue *queue, void *content)
{
	//create a node, then add it to the end of the linked list with content
	//
	//make sure to set the first and last pointers
	struct s_node *new;

	new = malloc(sizeof(struct s_node));
	new->next = 0;
	new->content = content;
	if (isEmpty(queue))
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		//set the last val to the new last
		queue->last->next = new;
		queue->last = new;
	}
}

void *dequeue(struct s_queue *queue)
{
	//remove a node from the start of the list, then set the first
	//
	//and last pointers as necessary
	//
	//return the content of the first item
	struct s_node *tmp = 0;
	void	*ret = 0;

	if (isEmpty(queue))
		return 0;
	//queue is not empty so we can dereference first node
	tmp = queue->first;
	ret = tmp->content;

	if (queue->first == queue->last)
	{
		tmp = queue->first;
		queue->first = 0;
		queue->last = 0;
		free(tmp);
	} //if queue has more than one item, pop the first in line, and free it
	else
	{
		tmp = queue->first;
		queue->first = queue->first->next;
		free(tmp);
	}
	return ret;
}


void *peek(struct s_queue *queue)
{
	//return the content of the first item of the queue
	//
	//if queue is empty return 0
	if (isEmpty(queue))
		return 0;
	return queue->first->content;
}


