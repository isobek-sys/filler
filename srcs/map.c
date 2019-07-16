/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:12:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/07/16 16:52:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			filler_get_map_param(t_filler *filler)
{
	char	*buf;
	char	*tmp;

	if (get_next_line(STDIN_FILENO, &buf) < 1)
		return (0);
	if (!ft_strstr(buf, "Plateau ") && !ft_strdel(&buf))
		return (0);
	tmp = buf;
	buf = ft_strstr(buf, " ") + 1;
	if ((!*buf || !(filler->map_y = ft_atoi(buf))) && !ft_strdel(&tmp))
		return (0);
	while (*buf && ft_isdigit(*buf))
		++buf;
	if ((!*buf || !(filler->map_x = ft_atoi(buf))) && !ft_strdel(&tmp))
		return (0);
	if (!(filler->map = (char **)malloc(((filler->map_y) + 1) * sizeof(char *))))
		return (filler_clear(filler));
	*(filler->map) = NULL;
	ft_strdel(&tmp);
	return (1);
}

int			filler_get_map(t_filler *filler)
{
	int		map_y;
	char	*buf;
	//
	int		fd;

	fd = open("./out", O_RDWR);
	if (fd == -1)
		ft_putendl_fd("ERROR", 2);

	buf = NULL;
	if (get_next_line(0, &buf) < 1)
		return (0);
	ft_strdel(&buf);
	map_y = 0;
	while (map_y < (filler->map_y) && get_next_line(STDIN_FILENO, &buf) > 0)
	{
		filler->map[map_y++] = buf;
		ft_putendl_fd(buf, fd);//
	}
	filler->map[map_y] = NULL;
//	get_next_line(0, &buf);
//	ft_putendl_fd(buf, fd);//
//	ft_strdel(&buf);
//	close(fd);
	return (0);
}