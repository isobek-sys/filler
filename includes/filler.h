/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:43:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/16 12:20:40 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <ft_printf.h>
# include <fcntl.h>

typedef struct	s_filler
{
	char		player;
	char		**map;
	int			map_x;
	int			map_y;
	char		**piece;
}				t_filler;

int			filler_clear(t_filler *filler);
t_filler	*filler_init(void);
char		**filler_read(t_filler *filler);
char		**filler_realloc(char **arr, char *str);
int			filler_get_player(t_filler *filler, char *buf);
int			filler_get_map_param(t_filler *filler);
int			filler_get_map(t_filler *filler);

#endif
