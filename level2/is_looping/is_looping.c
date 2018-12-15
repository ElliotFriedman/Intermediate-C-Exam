/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:10:41 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 10:15:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

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
