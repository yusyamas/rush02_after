/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:35:59 by yusyamas          #+#    #+#             */
/*   Updated: 2022/12/13 00:52:52 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define UINT_MAX 4294967295LL

typedef struct s_key
{
	int				strn;
	int				real;
	int				exp;
	char			*value;
}					t_key;
typedef struct s_dict
{
	bool			flag;
	int				strn;
	int				base_num;
	int				**real;
	int				**exp;
	char			*num;
	char			**value;
}					t_dict;
typedef struct s_state
{
	unsigned int	num;
	char			*str;
	int				**real;
	int				**exp;
}					t_state;
typedef struct s_rush
{
	t_dict			*dict;
	t_key			*key;
	t_state			state;
}					t_rush;

char				*input_str(char *str);
int					print_error(int err_no);
t_dict				*input_dict(char *str);
long long			my_atoi(char *str);
char				**ft_split(char *str, char *charset);
bool				num_format_check(t_dict *dict, int i, char *num);
int					set_dict(t_dict *dict, t_key *key);
void				set_dict_strn(t_dict *dict);
void				set_dict_base_num(t_dict *dict);
int					get_base_num(char *num);
void				ft_sort_struct(t_dict *dict, int size);
t_key				*key_init(void);
int					get_base_num_dict(t_key *key, char *num);
bool				dict_decide(t_dict *dict, t_key *key, int maxn);
bool				digit1000_check(int i, char *num, int len);
bool				decide_key(t_dict *dict, t_key *key);

#endif
