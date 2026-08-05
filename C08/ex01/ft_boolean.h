/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:49:28 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 18:01:42 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define FT_BOOLEAN_H
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

void	ft_putstr(char *str);

#endif