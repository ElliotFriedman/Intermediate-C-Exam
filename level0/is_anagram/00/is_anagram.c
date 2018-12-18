/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:06:42 by efriedma          #+#    #+#             */
/*   Updated: 2018/11/27 01:25:37 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	sortlex(char *str)
{
	int register		i;
	int register		cnt[128];
	int register		ctr;
	char register		tmp;
	int register		j;

	i = 0;
	ctr = 0;
	while (i < 128)
	{
		cnt[i] = 0;
		i++;
	}
	i = 0;
	while (str[i])
	{
		cnt[(int)str[i]] += 1;
		i++;
	}
	i = 0;
	while (i < 128)
	{
		j = cnt[i];
		tmp = i;
		while (j && tmp)
		{
			str[ctr] = tmp;
			ctr++;
			j--;
		}
		i++;
	}
}

static int	ft_strlen(char *str)
{
	int register	i = 0;

	while (str[i])
		i++;
	return i;
}

int	is_anagram(char *a, char *b)
{
	int	register i = ft_strlen(a);
	int register x = ft_strlen(b);

	if (i != x)
		return 0;
	sortlex(a);
	sortlex(b);
	i = 0;
	while (i < x)
	{
		if (a[i] != b[i])
			return 0;
		i++;
	}
	return 1;
}
