/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:35:43 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 15:14:18 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	count_un(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_strrev2(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_unitoa(unsigned int n)
{
	char	*out;
	int		i;

	i = 0;
	out = malloc(sizeof(char) * (count_un(n) + 2));
	if (!out)
		return (NULL);
	if (n == 0)
		out[i++] = '0';
	while (n != 0)
	{
		out[i++] = (n % 10) + '0';
		n /= 10;
	}
	out[i] = '\0';
	ft_strrev2(out);
	return (out);
}
