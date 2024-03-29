/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:41:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/28 18:05:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*filler_get_line(void)
{
	char	*line;
	char	*tmp;
	char	*buf;
	int		ret;

	tmp = NULL;
	buf = ft_strnew(1);
	line = ft_strnew(0);
	while ((ret = read(STDIN_FILENO, buf, 1)) && *buf != '\n')
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		ft_strdel(&tmp);
	}
	if (buf)
		ft_strdel(&buf);
	if (*line)
		return (line);
	if (line)
		ft_strdel(&line);
	if (tmp)
		ft_strdel(&tmp);
	return (NULL);
}

char		 **filler_realloc(char **arr, char *str)
{
	char	**tmp;
	int		i;

	if (!arr)
		arr = (char **)malloc(2 * sizeof(char *));
	else
	{
		tmp = arr;
		arr = (char **)malloc((ft_strlenarr(tmp) + 2) * sizeof(char *));
		i = -1;
		while (tmp[++i])
			arr[i] = tmp[i];
		arr[i++] = str;
		arr[i] = NULL;
		ft_str_del_arr(tmp);
		return (arr);
	}
	*arr = str;
	*(arr + 1) = NULL;
	return (arr);
}

int			filler_get_players(t_filler *filler)
{
	char	*buf;

	if (!(buf = filler_get_line()))
		return (0);
	if (!ft_strstr(buf, "$$$ exec ") && !ft_strdel(&buf))
		return (0);
	if (ft_strstr(buf, "p1") && !ft_strdel(&buf))
	{
		filler->player_s1 = 'O';
		filler->player_s2 = 'o';
		filler->hostile_s1 = 'X';
		filler->hostile_s2 = 'x';
		return (1);
	}
	if (ft_strstr(buf, "p2") && !ft_strdel(&buf))
	{
		filler->player_s1 = 'X';
		filler->player_s2 = 'x';
		filler->hostile_s1 = 'O';
		filler->hostile_s2 = 'o';
		return (1);
	}
	ft_strdel(&buf);
	return (0);
}

int			filler_read(t_filler *filler)
{
	if (!filler_get_map_param(filler))
		return (0);
	if (!filler_get_map(filler))
		return (0);
	if (!(filler->player_lm_x) && !(filler->player_lm_y))
		filler_get_last_move_players(filler);
	else
		filler_get_last_move_hostile(filler);
	if (!filler_get_piece_param(filler) || !filler_get_piece(filler))
		return (0);
	filler_get_minimal_piece(filler);
	return (1);
}
