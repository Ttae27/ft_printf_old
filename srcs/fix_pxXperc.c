/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_pxXperc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:29:33 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 18:50:24 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

char	*fix_p(char *split, va_list input)
{
	size_t	hex;
	char	*tmp1;
	char	*tmp2;
	char	*arg_p;
	char	*join;

	hex = va_arg(input, size_t);
	tmp1 = make_16p(hex, 'x');
	tmp2 = ft_calloc(3, sizeof(char));
	tmp2[0] = '0';
	tmp2[1] = 'x';
	join = ft_strjoin_free(tmp2, tmp1);
	arg_p = ft_strjoin_free(split, join);
	free(join);
	free(tmp1);
	return (arg_p);
}

char	*fix_capx(char *split, va_list input)
{
	unsigned int	hex;
	char			*tmp;
	char			*arg_capx;

	hex = va_arg(input, unsigned int);
	tmp = make_16(hex, 'X');
	arg_capx = ft_strjoin_free(split, tmp);
	free(tmp);
	return (arg_capx);
}

char	*fix_x(char *split, va_list input)
{
	unsigned int	hex;
	char			*tmp;
	char			*arg_x;

	hex = va_arg(input, unsigned int);
	tmp = make_16(hex, 'x');
	arg_x = ft_strjoin_free(split, tmp);
	free(tmp);
	return (arg_x);
}

char	*fix_perc(char *split, int len)
{
	char	*arg_perc;
	int		i;

	i = 0;
	arg_perc = malloc(sizeof(char) * (len + 2));
	while (split[i] != '\0')
	{
		arg_perc[i] = split[i];
		i++;
	}
	arg_perc[len] = '%';
	arg_perc[len + 1] = '\0';
	free(split);
	return (arg_perc);
}

char	*fix_pxxperc(char *split, va_list input, char mode)
{
	int				len;
	char			*out;

	len = ft_strlen(split);
	if (mode == 'p')
		out = fix_p(split, input);
	else if (mode == 'x')
		out = fix_x(split, input);
	else if (mode == 'X')
		out = fix_capx(split, input);
	else if (mode == '%')
		out = fix_perc(split, len);
	return (out);
}
