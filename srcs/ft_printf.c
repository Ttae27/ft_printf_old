/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:41:44 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/23 12:37:21 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	count_percent(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	j = 0;
	while (s1[i] != '\0')
		out[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		out[j++] = s2[i++];
	out[j] = '\0';
	free(s1);
	return (out);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	input;
	int		count;
	char	*list_mode;
	char	*str;
	int		trig;

	str = (char *)s;
	trig = 0;
	if (str[0] == '%' && str[2] != '\0')
		trig = 1;
	list_mode = mode_check(str, count_percent(str));
	va_start(input, s);
	count = print_out(str, 0, list_mode, input);
	va_end(input);
	if (trig == 1)
		list_mode--;
	free(list_mode);
	return (count);
}

// #include <stdio.h>
// int		main()
// {
// 	ft_printf(" %c %c %c ", '2', '1', 0);
// 	printf(" %c %c %c ", '2', '1', 0);
// }