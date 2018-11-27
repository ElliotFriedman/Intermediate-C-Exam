/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:30:17 by efriedma          #+#    #+#             */
/*   Updated: 2018/11/27 02:19:57 by efriedma         ###   ########.fr       */
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


struct s_stack *init(void)
{
	struct s_stack *new;

	new = malloc(sizeof(struct s_stack));
	new->top = 0;
	return new;
}

void *pop(struct s_stack *stack)
{
	struct s_node *tmp;

	tmp = 0;
	if (!stack || !stack->top)
		return 0;
	tmp = stack->top;
	stack->top = stack->top->next;
	return tmp;

}

int isEmpty(struct s_stack *stack)
{
	if (stack && stack->top)
		return (0);
	return (1);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *head;

	head = 0;
	if (stack)
	{
		head = malloc(sizeof(struct s_node));
		head->content = content;
		head->next = stack->top;
		stack->top = head;
	}
}

void *peek(struct s_stack *stack)
{
	if (stack && stack->top)
		return stack->top->content;
	return 0;
}
