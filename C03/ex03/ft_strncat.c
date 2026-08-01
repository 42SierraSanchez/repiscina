/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:15:51 by asierra           #+#    #+#             */
/*   Updated: 2026/07/31 14:19:15 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strncat(char *dest, const char *src, unsigned int n)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = strlen(dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
