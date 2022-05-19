/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:20:08 by phongpai          #+#    #+#             */
/*   Updated: 2022/05/19 21:19:10 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>
int		ft_printf(const char *s, ...);
char	*mode_check(char *s, int count);
int		count_percent(char *s);
char	*fix_csdiu(char *split, va_list input, char mode);
void	trim_firstchar(char *str);
char	**fix_firstchar(char *s, char *list_mode);
char	**fix_split(va_list input, char **split, char *list_mode);
char	*ft_unitoa(unsigned int n);
char	*fix_pxxperc(char *split, va_list input, char mode);
char	*make_16(unsigned int n, char mode);
char	*first_va(char *tmp, va_list input, char mode);
void	free_fix_out(char **fix, char *out, char **spilt);
char	*ft_strjoin_free(char *s1, char *s2);
char	*make_16p(size_t n, char mode);
int		print_out(char *str, int i, char *list_mode, va_list input);
void	ft_putstr(char *str);
#endif