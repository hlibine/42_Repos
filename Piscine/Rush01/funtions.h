/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrossell <rrossell@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:31:56 by rrossell          #+#    #+#             */
/*   Updated: 2023/07/23 22:31:58 by rrossell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check(int b[]);
void	swap(int *a, int *b);
void	ft_putchar(char c);
int		ft_line_check(int x, int y);
//Functions print_table file.
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_print_table(int border[], int table[4][4]);
void	ft_print_boxes(int row[4]);
void	ft_putint(int n);
int		count_boxes(int boxes[4]);
void	ft_rev_line(int line[], int reversed[4]);
int		ft_check_line(int line[], int n);
int		ft_strlen(char *str);
int		make_border_array(char border_str[], int border[]);
int		char_to_int(char c);
void	make_table(int table[4][4], int array[4], int start, int end, int row, int border[]);
int		table_check(int table[4][4], int border[]);
int		count_boxes(int boxes[4]);