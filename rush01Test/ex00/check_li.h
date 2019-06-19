/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_li.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:25:32 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 23:25:54 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_LI_H
# define CHECK_LI_H

int		check_li(int **sujet, int *soluce, int ligne, int direction);
int		check_ci(int **sujet, int *soluce, int colonne, int direction);
int		check_lc(int **sujet, int *soluce, int ligne);
int		checktout(int **sujet, int *soluce);
int		checkuneligne(int **sujet, int *soluce, int position);
int		checkunecolonne(int **sujet, int *soluce, int position);
void	solve(int **sujet, int *soluce, int position);
void	affichetout(int **sujet, int *soluce);
int		inputtest(int **sujet);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		check_argv(char *str);
char	*initialize(char *str, char *index);
int		get_base_index(char *str);
int		**get_tab(char *str, int nombre_arguments);

#endif
