/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_16p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:13:19 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 15:14:38 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	count_16p(size_t n)
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

char	*convert_p(int *tmp, int count, char mode)
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

char	*make_16p(size_t n, char mode)
{
	int			*tmp;
	char		*hex;
	size_t		tmp_n;
	int			i;

	tmp = malloc(sizeof(int) * count_16p(n));
	tmp_n = n;
	i = count_16p(n) - 1;
	while (n >= 16)
	{
		tmp[i--] = n % 16;
		n /= 16;
	}
	tmp[0] = n;
	hex = convert_p(tmp, count_16p(tmp_n), mode);
	return (hex);
}
