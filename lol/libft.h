/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:59:16 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/20 13:43:22 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>


size_t	ft_strlen(const char *str);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);

char	**ft_split(char const *s, char c);

char	*ft_itoa(int n);

#endif
