/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:16:22 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 10:22:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node);

int main()
{
	struct s_node *s0 = malloc(sizeof(struct s_node));
	struct s_node *s1 = malloc(sizeof(struct s_node));
	struct s_node *s2 = malloc(sizeof(struct s_node));
	struct s_node *s3 = malloc(sizeof(struct s_node));
	struct s_node *s4 = malloc(sizeof(struct s_node));
	struct s_node *s5 = malloc(sizeof(struct s_node));
	struct s_node *s6 = malloc(sizeof(struct s_node));

	s0->next = s1;
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = s6;
	s6->next = 0;

	printf("is this non-looping linked list looping? %s\n", is_looping(s0) == 1 ? "yes" : "no");

	s1->next = s0;
	printf("is this looping linked list looping? %s\n", is_looping(s0) == 1 ? "yes" :     "no");

	return 0;
}
