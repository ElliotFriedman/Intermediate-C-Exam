/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:46:08 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 11:07:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

#include <stdlib.h>
#include <string.h>

void perimeter(struct s_node *root);

int main()
{
	struct s_node *root = malloc(sizeof(struct s_node));
	struct s_node *root1 = malloc(sizeof(struct s_node));
	struct s_node *root2 = malloc(sizeof(struct s_node));
	struct s_node *root3 = malloc(sizeof(struct s_node));
	struct s_node *root4 = malloc(sizeof(struct s_node));
	struct s_node *root5 = malloc(sizeof(struct s_node));
	struct s_node *root6 = malloc(sizeof(struct s_node));
	struct s_node *root7 = malloc(sizeof(struct s_node));
	struct s_node *root8 = malloc(sizeof(struct s_node));
	struct s_node *root9 = malloc(sizeof(struct s_node));
	struct s_node *root10 = malloc(sizeof(struct s_node));
	struct s_node *root11 = malloc(sizeof(struct s_node));

	bzero((void*)root, sizeof(struct s_node));
	bzero((void*)root1, sizeof(struct s_node));
	bzero((void*)root2, sizeof(struct s_node));
	bzero((void*)root3, sizeof(struct s_node));
	bzero((void*)root4, sizeof(struct s_node));
	bzero((void*)root5, sizeof(struct s_node));
	bzero((void*)root6, sizeof(struct s_node));
	bzero((void*)root7, sizeof(struct s_node));
	bzero((void*)root8, sizeof(struct s_node));
	bzero((void*)root9, sizeof(struct s_node));
	bzero((void*)root10, sizeof(struct s_node));
	bzero((void*)root11, sizeof(struct s_node));
	
	root->left = root1;
	root1->left = root2;

	root->right = root3;
	root3->right = root4;
	root4->right = root5;
	root5->right = root6;
	root6->right = root7;
	root7->right = root8;
	root8->right = root9;
	root9->right = root10;
	root10->right = root11;

	root->value = 92;
	root1->value = 85;
	//go right at this val
	root2->value = 96;

	//this is all left
	root3->value = 9;
	root4->value = 8;
	root5->value = 7;
	root6->value = 6;
	root7->value = 5;
	root8->value = 4;
	root9->value = 3;
	root10->value = 2;
	root11->value = 1;

	perimeter(root);
	return 0;
}
