/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:06:00 by exam              #+#    #+#             */
/*   Updated: 2018/06/26 11:52:55 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		total = 0;

int		fisalpha(char a)
{
	if (a >= 'a' && a <= 'z')
		return (a - 96);
	if (a >= 'A' && a <= 'Z')
		return (a - 64);
	return (0);
}

void	print(int cnt[26], int frs[26])
{
	int	i;
	int	x;

	x = 0;
	i = 1;
	while (x < 26)
	{
		if (frs[x] == i)
		{
			total--;
			printf("%d%c", cnt[x], x + 97);
			if (total)
				printf(", ");
			i++;
			x = -1;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	static int	cnt[26];
	static int	frs[26];
	char 	*str;
	size_t	i;

	str = 0;
	i = 1;
	if (argc == 2)
	{
		str = argv[1];
		while (*str)
		{
			if (fisalpha(*str))
			{	
				if (!cnt[fisalpha(*str) - 1])
					total++;
				cnt[fisalpha(*str) - 1]++;
				if (!frs[fisalpha(*str) - 1])
				{
					frs[fisalpha(*str)- 1] += i;
					i++;
				}
			}
			str++;
		}
		print(cnt, frs);
	}
	printf("\n");
	return (0);
}
