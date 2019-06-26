/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 09:33:44 by cdoublet          #+#    #+#             */
/*   Updated: 2019/06/26 22:08:25 by cdoublet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_params
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
}				t_params;

typedef struct	s_coord
{
	int x;
	int y;
	int value;
}				t_coord;

char			*ft_create_files(char *file_name, char *tmp_map,
				t_params *params);
char			*ft_create_stdin(char *tmp_map, t_params *params);
char			*ft_create_tmp(char *file_name, char *tmp_map);
char			*ft_create_tmp_stdin(char *tmp_map);
int				ft_init_params(t_params *params, char *tmp_map);
int				ft_check_map(t_params *params, char *tmp_map);
int				ft_skipt_first_line(char *tmp_map);
int				ft_check_map2(t_params *params, char *tmp_map);
int				**ft_create_map(char *tmp_map, t_params *params, int **map);
int				**ft_map_alloc(t_params *params, int **map);
int				**ft_map_init(char *tmp_map, t_params *params, int **map);
int				**ft_solve(int x, int y, t_coord *bigger, int **t);
void			ft_is_bigger(t_coord *bigger, int i, int j, int pos);
int				ft_comp(int left, int up, int diag);
void			ft_init_bigger(t_coord *bigger);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *src1, char *src2);
void			ft_strcat(char *dest, char *src);
int				ft_strlen(char *str);
int				ft_open_file(char *file_name);
void			ft_display(int **map, t_params *params, t_coord *b);
int				ft_check_params(t_params *params);
void			ft_write_nl(void);
int				ft_check_same(t_params *params, char tmp_map);
int				ft_skipt_first_line_j(char *tmp_map, int i);

# define BUFFER_SIZE 1638400
# define L (i - 1)
# define U (j - 1)

#endif
