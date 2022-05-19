/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:57:05 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 18:59:08 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	trim_firstchar(char *str)
{
	int		i;

	i = 0;
	while (str[i + 1] != '\0' && str[i] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
}

char	**fix_firstchar(char *s, char *list_mode)
{
	char	**split;
	int		i;
	int		j;

	if (s[0] == '%')
		i = 0;
	else
		i = 1;
	j = 0;
	split = ft_split(s, '%');
	while (split[i] != NULL)
	{
		if (list_mode[i - 1] != '%')
			trim_firstchar(split[i]);
		i++;
	}
	return (split);
}

int	count_word(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

char	**fix_split(va_list input, char **split, char *list_mode)
{
	int		i;
	char	**out;

	i = 0;
	out = ft_calloc((count_word(split) + 1), sizeof(char *));
	out[count_word(split) - 1] = split[count_word(split) - 1];
	if (list_mode[count_word(split) - 1] == '%')
		out[count_word(split) - 1] = fix_pxxperc(split[count_word(split) - 1], \
		input, list_mode[count_word(split) - 1]);
	while (split[i] != NULL && split[i + 1] != NULL)
	{
		if (list_mode[i] == 'c' || list_mode[i] == 's' || list_mode[i] == 'd' \
		|| list_mode[i] == 'i' || list_mode[i] == 'u')
		{
			out[i] = fix_csdiu(split[i], input, list_mode[i]);
			i++;
		}
		if (list_mode[i] == 'p' || list_mode[i] == 'x' \
		|| list_mode[i] == 'X' || list_mode[i] == '%')
		{
			out[i] = fix_pxxperc(split[i], input, list_mode[i]);
			i++;
		}
	}
	return (out);
}
