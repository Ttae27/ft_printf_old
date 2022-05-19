/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:36:17 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 21:32:21 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

char	*fill_mode(char *contain, char s, int count_order)
{
	if (s == 'c')
		contain[count_order] = 'c';
	else if (s == 's')
		contain[count_order] = 's';
	else if (s == 'd')
		contain[count_order] = 'd';
	else if (s == 'i')
		contain[count_order] = 'i';
	else if (s == 'u')
		contain[count_order] = 'u';
	else if (s == 'p')
		contain[count_order] = 'p';
	else if (s == 'x')
		contain[count_order] = 'x';
	else if (s == 'X')
		contain[count_order] = 'X';
	else if (s == '%')
		contain[count_order] = '%';
	return (contain);
}

char	*mode_check(char *s, int count)
{
	char	*contain;
	int		i;
	int		count_order;

	count_order = 0;
	i = 0;
	contain = ft_calloc(count + 1, sizeof(char));
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			fill_mode(contain, s[i], count_order);
			count_order++;
		}
		i++;
	}
	return (contain);
}
