/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:58:34 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/12 16:36:11 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

void			ft_putchar(char c);
void			ft_swap(int *a, int *b);
void			ft_putstr(char *str);
unsigned int	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_memcpy(char *dest, char *src, unsigned int n);
unsigned int	ft_strcspn(char *s1, char *s2);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_isdigit(char c);
int				ft_min(int a, int b);

#endif
