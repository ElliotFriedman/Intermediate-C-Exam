/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 09:49:07 by exam              #+#    #+#             */
/*   Updated: 2018/07/24 10:10:17 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct	s_node
{
	void			*content;
	struct s_node	*next;
};

struct	s_queue
{
	struct s_node	*first;
	struct s_node	*last;
};


struct	s_queue *init(void)
{
	struct s_queue *n = malloc(sizeof(struct s_queue));
	n->first = 0;
	n->last = 0;
	
	return (n);
}

void	enqueue(struct s_queue *queue, void *content)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	struct s_node *iter = queue->first;

	node->content = content;
	node->next = 0;
	if (!iter)
	{
		queue->first = node;
		queue->last = node;
	}
	else
	{
		while (iter->next != 0)
			iter = iter->next;
		iter->next = node;
		queue->last = node;
	}
}

void	*dequeue(struct s_queue *queue)
{
	void			*tmp;
	struct s_node	*n;

	if (!queue)
		return (0);
	n = queue->first;
	tmp = queue->first->content;
	queue->first = queue->first->next;	
	free(n);
	
	return (tmp);
}

void	*peek(struct s_queue *queue)
{
	if (queue)
		return (queue->first->content);
	return (0);
}

int		isEmpty(struct s_queue *queue)
{
	if (queue->first)
		return (0);
	return (1);
}
