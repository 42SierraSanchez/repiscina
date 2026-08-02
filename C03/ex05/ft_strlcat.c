/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:56:13 by asierra           #+#    #+#             */
/*   Updated: 2026/08/02 13:01:22 by asierra          ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int i;

	dest_len = strlen(dest);
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
    
	return (ft_strlen(dest) + ft_strlen(src))
}