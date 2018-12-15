/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:28:27 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 12:26:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

//return index of node which is another node's pointer to other in relation to start which is the beginning of the list
int		globalindex(struct s_node *node, struct s_node *start)
{
	int i = 0;

	if (!node)
		return -1;
	while (start != 0 && start != node)
	{
		start = start->next;
		i++;
	}
	return i;
}

//given an index return the node from this index
struct s_node *returnindex(int i, struct s_node *ret)
{
	if (i == -1)
		return 0;
	
	struct s_node *iter = ret;
	while (iter && i)
	{
		iter = iter->next;
		i--;
	}
	return iter;

}

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *ret = 0;
	struct s_node *tmp = node;

	if (!node)
		return 0;
	ret = malloc(sizeof(struct s_node));
	ret->data = tmp->data;
	struct s_node *ret1 = ret;
	while (tmp)
	{
		ret1->data = tmp->data;
		
		if (tmp->next)
			ret1->next = malloc(sizeof(struct s_node));
		else
			ret1->next = 0;
		ret1 = ret1->next;	
		tmp = tmp->next;
	}
	tmp = node;
	ret1 = ret;
	while (tmp)
	{
		ret1->other = returnindex(globalindex(tmp->other, node), ret);
		ret1 = ret1->next;
		tmp = tmp->next;
	}
	return ret;
}
