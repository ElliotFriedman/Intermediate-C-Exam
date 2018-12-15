/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:58:29 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 12:25:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int data;
	struct s_node *next;
	struct s_node *other;
};


struct s_node *clone_list(struct s_node *node);

int		is_looping(struct s_node *node)
{
	struct s_node *s0 = 0;
	struct s_node *s1 = 0;

	if (!node)
		return 0;
	s0 = node;
	s1 = node->next;
	while (s1 && s0)
	{
		if (s1 == s0)
			return 1;
		s1 = s1->next;
		if (s1)
			s1 = s1->next;
		s0 = s0->next;
	}
	return 0;
}

int main()
{
	struct s_node *s0 = malloc(sizeof(struct s_node));
	struct s_node *s1 = malloc(sizeof(struct s_node));
	struct s_node *s2 = malloc(sizeof(struct s_node));
	struct s_node *s3 = malloc(sizeof(struct s_node));
	struct s_node *s4 = malloc(sizeof(struct s_node));
	struct s_node *s5 = malloc(sizeof(struct s_node));
	struct s_node *s6 = malloc(sizeof(struct s_node));

	bzero((void*)s0, sizeof(struct s_node));
	bzero((void*)s1, sizeof(struct s_node));
	bzero((void*)s2, sizeof(struct s_node));
	bzero((void*)s3, sizeof(struct s_node));
	bzero((void*)s4, sizeof(struct s_node));
	bzero((void*)s5, sizeof(struct s_node));
	bzero((void*)s6, sizeof(struct s_node));

	s0->next = s1;
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = s6;
	s6->next = 0;
	s0->data = 0;

	printf("is this non-looping linked list looping? %s\n", is_looping(s0) == 1 ? "yes" : "no");
	struct s_node *tmp = clone_list(s0);
	
	printf("is this copied non-looping linked list looping? %s\n", is_looping(tmp) == 1 ? "yes"     : "no");

	
	s1->next = s0;
	//tmp = clone_list(s0);
	printf("is this copied looping linked list looping? %s\n", is_looping(tmp) == 1     ? "yes"     : "no");
	printf("is this looping linked list looping? %s\n", is_looping(s0) == 1 ? "yes" :     "no");

	return 0;
}
