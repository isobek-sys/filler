/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:43:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/15 13:04:41 by blukasho         ###   ########.fr       */
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
	char		**piece;
}				t_filler;

void		*filler_clear(t_filler *filler);
t_filler	*filler_init(void);
char		**filler_read(t_filler *filler);
char		**filler_realloc(char **arr, char *str);
int			filler_get_player(t_filler *filler, char *buf);

#endif
