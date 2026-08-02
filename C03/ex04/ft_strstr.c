/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:21:59 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 12:58:35 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	to_find_len;

	i = 0;
	j = 0;
	to_find_len = ft_strlen(to_find);
	while (str[i])
	{
		if (str[i] == to_find[i])
		{
			j = i;
			while (str[i] == to_find[i])
			{
				if (i - j == to_find_len)
					return (&str[j]);
				i++;
			}
			i = j;
			j = 0;
		}
		i++;
	}
	return ("NULL");
}

/* #include <stdio.h>
int main (void)
{
char str[] = "los perros salvajes";
char to_find[] = "perros";
printf("to find en str es %s", ft_strstr(str, to_find));
}
 */