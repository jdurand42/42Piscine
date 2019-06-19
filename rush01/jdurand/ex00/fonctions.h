/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:30:02 by jdurand           #+#    #+#             */
/*   Updated: 2019/06/16 23:30:04 by jdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTIONS_H
# define FONCTIONS_H
# include "check_li.h"

int		checkuneligne(int **sujet, int *soluce, int position);
int		checkunecolonne(int **sujet, int *soluce, int position);
void	solve(int **sujet, int *soluce, int position);
int		inputtest(int **sujet);

#endif
