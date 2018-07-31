/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:29:17 by exam              #+#    #+#             */
/*   Updated: 2018/07/31 12:10:57 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack	*init(void)
{
	struct s_stack *new = malloc(sizeof(struct s_stack));
	new->top = 0;
	return (new);
}

void	*pop(struct s_stack *stack)
{
	struct s_stack *tmp = stack;
	stack = 0;
	return ((void*)tmp->top->content);
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node *n_head = malloc(sizeof(struct s_node));
	n_head->next = 0;
	n_head->content = content;

	stack->top = (struct s_node*)content;
}

void	*peek(struct s_stack *stack)
{
	if (stack && stack->top)
		return (stack->top->content);
	return (0);
}

int isEmpty(struct s_stack *stack)
{
	if (stack)
		return (1);	
	return (0);
}
