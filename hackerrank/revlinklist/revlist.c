/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 00:13:32 by efriedma          #+#    #+#             */
/*   Updated: 2018/12/17 00:29:53 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *next;
};

//reverse a list in place

void	revList(struct s_node *list)
{
	struct s_node *curr;
	struct s_node *prev;
	struct s_node *next;

	if (!list)
		return ;
	curr = list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

}

int main()
{
	struct s_node *n0 = malloc(sizeof(struct s_node));
	struct s_node *n1 = malloc(sizeof(struct s_node));
	struct s_node *n2 = malloc(sizeof(struct s_node));
	struct s_node *n3 = malloc(sizeof(struct s_node));
	
	n0->value = 0;
	n1->value = 1;
	n2->value = 2;
	n3->value = 3;
	
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = 0;

	revList(n0);

	struct s_node *curr = n3;
	while (curr)
	{
		printf("val: %d\n", curr->value);
		curr = curr->next;
	}


	return 0;
}
