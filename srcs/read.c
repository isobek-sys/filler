/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:41:58 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/19 11:40:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

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

int			filler_get_player(t_filler *filler)
{
	char	*buf;

	if (get_next_line(STDIN_FILENO, &buf) < 1)
		return (0);
	if (!ft_strstr(buf, "$$$ exec "))
		return (0);
	if (ft_strstr(buf, "p1") && (filler->player = 'O') && !ft_strdel(&buf))
		return (1);
	if (ft_strstr(buf, "p2") && (filler->player = 'X') && !ft_strdel(&buf))
		return (1);
	ft_strdel(&buf);
	return (0);
}

int			filler_read(t_filler *filler)
{
	if (!filler_get_map_param(filler))
		return (0);
	if (!filler_get_map(filler))
		return (0);
	if (!filler_get_piece_param(filler) || !filler_get_piece(filler))
		return (0);
	return (1);
}
