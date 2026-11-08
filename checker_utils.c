/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 20:48:54 by maltahay          #+#    #+#             */
/*   Updated: 2026/11/07 20:48:57 by maltahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_line(int fd, char **line)
{
	char	buf[64];
	char	c;
	int		i;
	int		r;

	i = 0;
	r = read(fd, &c, 1);
	while (r > 0 && c != '\n' && i < 60)
	{
		buf[i++] = c;
		r = read(fd, &c, 1);
	}
	if (r < 0 || (r == 0 && i == 0))
		return (0);
	buf[i] = '\0';
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if (!*line)
		return (0);
	i = -1;
	while (buf[++i])
		(*line)[i] = buf[i];
	(*line)[i] = '\0';
	return (1);
}

static int	apply_op_more(const char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op, "ra") == 0)
		op_ra(a);
	else if (ft_strcmp(op, "rb") == 0)
		op_rb(b);
	else if (ft_strcmp(op, "rr") == 0)
		op_rr(a, b);
	else if (ft_strcmp(op, "rra") == 0)
		op_rra(a);
	else if (ft_strcmp(op, "rrb") == 0)
		op_rrb(b);
	else if (ft_strcmp(op, "rrr") == 0)
		op_rrr(a, b);
	else
		return (0);
	return (1);
}

int	apply_op(const char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op, "sa") == 0)
		op_sa(a);
	else if (ft_strcmp(op, "sb") == 0)
		op_sb(b);
	else if (ft_strcmp(op, "ss") == 0)
		op_ss(a, b);
	else if (ft_strcmp(op, "pa") == 0)
		op_pa(a, b);
	else if (ft_strcmp(op, "pb") == 0)
		op_pb(a, b);
	else
		return (apply_op_more(op, a, b));
	return (1);
}

void	read_and_exec(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (read_line(0, &line))
	{
		if (!apply_op(line, a, b))
		{
			free(line);
			ft_error(a, b);
		}
		free(line);
		line = NULL;
	}
}
