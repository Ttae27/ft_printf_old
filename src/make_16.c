/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:23:48 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 15:26:07 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	count_16(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

char	*convert(int *tmp, int count, char mode)
{
	int		i;
	char	*out;

	i = 0;
	out = ft_calloc(count + 1, sizeof(char));
	while (count > 0)
	{
		if (tmp[i] < 10)
			out[i] = tmp[i] + '0';
		else if (tmp[i] >= 10 && mode == 'x')
			out[i] = tmp[i] - 10 + 'a';
		else
			out[i] = tmp[i] - 10 + 'A';
		i++;
		count--;
	}
	free(tmp);
	return (out);
}

char	*make_16(unsigned int n, char mode)
{
	int		*tmp;
	char	*hex;
	int		tmp_n;
	int		i;

	tmp = malloc(sizeof(int) * count_16(n));
	tmp_n = n;
	i = count_16(n) - 1;
	while (n >= 16)
	{
		tmp[i--] = n % 16;
		n /= 16;
	}
	tmp[0] = n;
	hex = convert(tmp, count_16(tmp_n), mode);
	return (hex);
}
