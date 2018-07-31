/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 11:43:29 by efriedma          #+#    #+#             */
/*   Updated: 2018/07/31 11:53:07 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	size_t	iter_a = 0;
	size_t	iter_b = 0;

	while ((int)iter_a < na && (int)iter_b < nb)
	{
		if (a[iter_a] == b[iter_b])
		{
			printf("%d", a[iter_a]);
			iter_a++;
			iter_b++;
			if ((int)iter_a != na && (int)iter_b != nb)
				printf(" ");
		}
		if (a[iter_a] > b[iter_b])
			iter_b++;
		else if (a[iter_a] < b[iter_b])
			iter_a++;
	}
	printf("\n");
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[11] = {2,3,4,5,6,7,8,9,10,11};

	print_doublon(a, 10, b, 11);

}
