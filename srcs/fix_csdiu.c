/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_csdiu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:20:24 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/23 10:15:27 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

char	*fix_c(char *split, va_list input, int len)
{
	char	tmp;
	char	*arg_c;
	int		i;

	i = 0;
	tmp = va_arg(input, int);
	arg_c = malloc(sizeof(char) * (len + 2));
	while (split[i] != '\0')
	{
		arg_c[i] = split[i];
		i++;
	}
	arg_c[len] = tmp;
	arg_c[len + 1] = '\0';
	free(split);
	//printf("arg_c = %s\n", arg_c);
	return (arg_c);
}

char	*fix_s(char *split, va_list input)
{
	char	*arg_s;
	char	*tmp;

	tmp = va_arg(input, char *);
	arg_s = ft_strjoin_free(split, tmp);
	return (arg_s);
}

char	*fix_u(char *split, va_list input)
{
	unsigned int	num;
	char			*tmp;
	char			*arg_u;

	num = va_arg(input, unsigned int);
	tmp = ft_unitoa(num);
	arg_u = ft_strjoin_free(split, tmp);
	free(tmp);
	return (arg_u);
}

char	*fix_d_i(char *split, va_list input)
{
	int		i;
	int		num;
	char	*tmp;
	char	*arg_d;

	num = va_arg(input, int);
	tmp = ft_itoa(num);
	arg_d = ft_strjoin_free(split, tmp);
	free(tmp);
	return (arg_d);
}

char	*fix_csdiu(char *split, va_list input, char mode)
{
	int		len;
	char	*out;

	len = ft_strlen(split);
	if (mode == 'c')
		out = fix_c(split, input, len);
	else if (mode == 's')
		out = fix_s(split, input);
	else if (mode == 'd' || mode == 'i')
		out = fix_d_i(split, input);
	else if (mode == 'u')
		out = fix_u(split, input);
	return (out);
}
