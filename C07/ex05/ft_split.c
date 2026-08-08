/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 23:58:16 by asierra           #+#    #+#             */
/*   Updated: 2026/08/08 19:16:48 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	first;

	first = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_in_charset(str[i], charset) && first)
		{
			count++;
			first = 0;
		}
		else if (is_in_charset(str[i], charset) && !first)
			first = 1;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**splitted;
	int		word_count;

	word_count = 0;
	splitted = malloc(count_words(str, charset) * (sizeof(char *)) + 1);
	if (!splitted)
		return (0);
	i = 0;
	while (str[i])
	{
		while (is_in_charset(str[i], charset))
		{
			j = i;
			i++;
		}
		splitted[word_count] = malloc(j - i + 1);
		int k = 0;
		while (j < i)
		{
			splitted[word_count][k] = str[j];
			j++;
		}
		splitted[word_count][j - i] = '\0';
		word_count++;
		i++;
	}
	splitted[word_count] = NULL;
	return (splitted);
}

int	main(int argc, char **argv)
{
	char *str = argv[1];
	char *charset = ", ";
	char **splitted;

	if (argc != 2)
		return (1);
	printf("argv[1] is: \"%s\"\n charset is : \"%s\"\n", str, charset);
	splitted = ft_split(str, charset);

	int i = 0;
	while (splitted[i] != NULL)
	{
		printf("%s\n", splitted[i]);
		i++;
	}
	return (0);
}