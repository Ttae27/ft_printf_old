/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 02:26:56 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 19:00:22 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

char	*first_va(char *tmp, va_list input, char mode)
{
	char	*out;

	if (mode == 'c' || mode == 's' || mode == 'd' \
	|| mode == 'i' || mode == 'u')
		out = fix_csdiu(tmp, input, mode);
	if (mode == 'p' || mode == 'x' || mode == 'X' || mode == '%')
		out = fix_pxxperc(tmp, input, mode);
	return (out);
}
