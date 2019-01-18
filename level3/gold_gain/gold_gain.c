/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 01:19:36 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/18 02:00:43 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


int		gold_gain(int **arr, int n)
{
	if (!n)
		return 0;
	if (n == 1)
		return arr[0][0];

	int	**cpyArr = malloc(sizeof(int *) * n);
	int i = 0;

	while (i < n)
	{
		cpyArr[i] = malloc(sizeof(int) * n);
		i++;
	}

	i = 0;
	while (i < n)
	{
		cpyArr[n - 1][i] = arr[n - 1][i];
		i++;
	}

	//make sure you are looking from second to last column
	i = n - 2;
	while (i > -1)
	{
		int j = 0;
		//loop through all items in each column
		while (j < n)
		{
			//Problem here with math, too tired to figure out now
			int a = arr[i][ j + 1 < n ? j + 1 : j ];
			int b = arr[i][ j ];
			int c = arr[i][ j - 1 > -1 ? j - 1 : j];
			printf("a: %d, b: %d, c: %d\n", a, b, c);
			a = b > a ? b : a;
			a = c > a ? c : a;
			printf("now a: %d\n", a);
			cpyArr[i][j] = arr[i][j] + a;

			j++;
		}
		i--;
	}

	i = 0;
	int max = cpyArr[0][0];
	while (i < n)
	{
		if (cpyArr[i][0] > max)
			max = cpyArr[i][0];
		printf("%d %d %d\n", cpyArr[i][0], cpyArr[i][1], cpyArr[i][2]);
		i++;
	}
	return max;
}

int main()
{
	int	**arr = malloc(sizeof(int *) * 9);
	arr[0] = malloc(sizeof(int) * 3);
	arr[1] = malloc(sizeof(int) * 3);
	arr[2] = malloc(sizeof(int) * 3);

	arr[0][0] = 10;
	arr[0][1] = 20;
	arr[0][2] = 30;

	arr[1][0] = 10;
	arr[1][1] = 150;

	arr[1][2] = 100;

	arr[2][0] = 100;
	arr[2][1] = 2000;
	arr[2][2] = 200;

	printf("max: %d\n", gold_gain(arr, 3));

	return 0;
}
