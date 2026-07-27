/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 22:06:59 by asierra           #+#    #+#             */
/*   Updated: 2026/07/26 23:00:39 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%c\n", i[str]);
		printf("%d\n", i);
		if (i[srt] >= 65 && i[str] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "HoLa MunDo CrueL";

	printf("%s\n", str);
	ft_strlowcase(str);
	printf("%s\n", str);
	return (0);
}
*/
