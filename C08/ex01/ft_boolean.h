/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asierra <asierra@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:49:28 by asierra           #+#    #+#             */
/*   Updated: 2026/08/05 18:08:13 by asierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

#define SUCCESS= 0;
#define EVEN= nbr % 2 == 0;
#define EVEN_MESSAGE = "I have an even number of arguments.\n"
#define ODD_MESSAGE = "I have an odd number of arguments.\n"



typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

void	ft_putstr(char *str);

#endif