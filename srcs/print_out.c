/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:07:24 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/23 10:15:31 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

void	free_fix_out(char **fix, char *out, char **split)
{
	int	i;

	i = 0;
	while (fix[i] != NULL)
		free(fix[i++]);
	free(fix);
	free(out);
	free(split);
}

int	print_out(char *str, int i, char *list_mode, va_list input)
{
	char	*tmp;
	char	**split;
	char	**fix;
	char	*out;
	int		len;

	tmp = ft_calloc(1, sizeof(char));
	if (str[0] == '%')
	{
		tmp = first_va(tmp, input, list_mode[0]);
		list_mode++;
	}
	split = fix_firstchar(str, list_mode);
	//printf("split = %s\n",split[0]);
	fix = fix_split(input, split, list_mode);
	//printf("fix = %s\n",fix[0]);
	out = ft_strjoin_free(tmp, fix[i]);
	//printf("out = %s\n",out);
	while (fix[i + 1] != NULL)
	{
		out = ft_strjoin_free(out, fix[i + 1]);
		i++;
	}
	ft_putstr(out);
	len = ft_strlen(out);
	free_fix_out(fix, out, split);
	return (len);
}
