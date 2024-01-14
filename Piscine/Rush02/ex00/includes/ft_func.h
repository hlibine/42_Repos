/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuravye <smuravye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:24:02 by smuravye          #+#    #+#             */
/*   Updated: 2023/07/30 21:56:05 by smuravye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNC_H
# define FT_FUNC_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char			*dict_to_string(char *dict_file);
void			filter_number(char *dict, long long nbr);
long long		ft_atoi(char *str);
char			*ft_itoa(int num);
void			ft_putstr(char *str);
char			*ft_simple_strjoin(char *str, char c);
long long		ft_strstr(char *str, char *to_find);
int				ft_wordfilter(char *str);
void			get_billions(char *dict, long long nbr);
void			get_millions(char *dict, long long nbr);
void			get_thousands(char *dict, long long nbr);
void			get_hundreds(char *dict, long long nbr);
int				print_dicterror(void);
int				print_error(void);
long long		ft_strstr_zero(char *str, char *to_find);

#endif
