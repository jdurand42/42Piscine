/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:47:45 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 22:25:44 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

void	ft_putstr(char *str);
int		check_argv(char *str);
char	*initialize(char *str, char *index);
int		get_base_index(char *str);
int		**get_tab(char *str, int nombre_arguments);

#endif
