/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:43:32 by efriedma          #+#    #+#             */
/*   Updated: 2018/07/31 12:49:36 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *next;
};

int		is_looping(struct s_node *node)
{
	struct s_node	*i1 = node->next->next;
	struct s_node   *i2 = node;

	while (i1 && i2)
	{
		if (i1 == i2)
			return (1);
		i1 = i1->next;
		i2 = i2->next->next;
	}
	return (0);
}
