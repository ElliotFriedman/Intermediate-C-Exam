/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:34:34 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 11:22:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

int		prev = 0;

struct s_node *g_root;

void	left(struct s_node *root)
{
	if (root)
	{
		if (prev)
			printf(" ");
		prev = 1;
		printf("%d", root->value);
		left(root->left);
	}
}

int		hvisit(int left, struct s_node *root, struct s_node *find)
{
	if (root == find)
		return 1;
	else if (!root)
		return 0;
	return (left ? hvisit(1, root->left, find) : hvisit(0, root->right, find));
}

void	depth(struct s_node *root)
{
	if (root)
	{
		if (!root->left && !root->right && !hvisit(0, g_root, root) && !hvisit(1, g_root, root))
		{
			if (prev)
				printf(" ");
			prev = 1;
			printf("%d", root->value);
			root = 0;
		}
		else
		{
			depth(root->left);
			depth(root->right);
		}
	}
}

void    right(struct s_node *root)
{
	if (root)
	{
		if (!hvisit(0, root, g_root))
		{
			right(root->right);
			if (prev)
				printf(" ");
			prev = 1;
			printf("%d", root->value);
		}
	}
}

void perimeter(struct s_node *root)
{
	g_root = root;
	left(root);
	depth(root);
	right(root->right);

	printf("\n");
}
