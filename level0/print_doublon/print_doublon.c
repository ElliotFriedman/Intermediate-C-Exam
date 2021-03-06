/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 09:04:52 by exam              #+#    #+#             */
/*   Updated: 2018/12/11 09:09:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int		ai = 0;
	int		bi = 0;
	int		b00l = 0;

	while (ai < na && bi < nb)
	{
		if (a[ai] == b[bi])
		{
			if (b00l)
				printf(" ");
			printf("%d", a[ai]);
			ai++;
			bi++;
			b00l = 1;
		}
		else if (a[ai] > b[bi])
			bi++;
		else
			ai++;
	}
	printf("\n");
}
