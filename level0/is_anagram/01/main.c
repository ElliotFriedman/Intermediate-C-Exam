/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:31:40 by efriedma          #+#    #+#             */
/*   Updated: 2018/12/18 09:38:37 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_anagram(char *a, char *b);

int main()
{
	printf("is .123?. an anagram of ?321..? %s\n", is_anagram(".123?.", "?321..?") == 1 ? "yes" : "no");
	printf("is .123?. an anagram of ?321.. %s\n", is_anagram(".123?.", "?321..") == 1 ? "yes" : "no");
	printf("is bcab an anagram of abca? %s\n", is_anagram("bcab", "abca") == 1 ? "yes" : "no");
	printf("is abcdef an anagram of fabcde? %s\n", is_anagram("abcdef", "fabcde") == 1 ? "yes" : "no");

	return 0;
}
