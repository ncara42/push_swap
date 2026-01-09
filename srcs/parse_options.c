/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:53:01 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/09 19:16:36 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_optype	which_option(char *optionstr)
{
	if ((ft_strcmp(optionstr, "bench")) == 0)
		return (BENCH);
	else if ((ft_strcmp(optionstr, "adaptive")) == 0)
		return (ADAPTIVE);
	else if ((ft_strcmp(optionstr, "simple")) == 0)
		return (SIMPLE);
	else if ((ft_strcmp(optionstr, "medium")) == 0)
		return (MEDIUM);
	else if ((ft_strcmp(optionstr, "complex")) == 0)
		return (COMPLEX);
	return (UNKNOWN);
}

int	verify_options(t_options **options)
{
	int	i;
	int	algo_count;

	algo_count = 0;
	i = 0;
	while (i < (*options)->count)
	{
		if ((*options)->options[i] != BENCH)
			algo_count++;
		i++;
	}
	if (algo_count > 1)
		return (0);
	return (1);
}

int	get_opts_from_argv(int argc, char **argv, int *bench, t_optype *algo)
{
	int			i;
	t_optype	opt;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
		{
			if (*bench)
				return (3);
			*bench = 1;
		}
		else if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			opt = which_option(&argv[i][2]);
			if (opt != UNKNOWN && opt != BENCH)
			{
				if (*algo != UNKNOWN && *algo != opt)
					return (3);
				*algo = opt;
			}
		}
		i++;
	}
	return (0);
}

int	select_option(t_optype *opt, t_stats *st, t_options *o)
{
	if (o->count == 2)
	{
		st->isbench = 1;
		if (o->options[0] != BENCH)
			*opt = o->options[0];
		else
			*opt = o->options[1];
	}
	else if (o->count == 1)
	{
		if (o->options[0] == BENCH)
		{
			st->isbench = 1;
			st->isadaptive = 1;
		}
		else
			*opt = o->options[0];
	}
	return (1);
}

int	parse_options(int argc, char **argv, t_options **options)
{
	t_optype		algo;
	int				bench;
	int				err;

	algo = UNKNOWN;
	bench = 0;
	*options = malloc(sizeof(t_options));
	if (!*options)
		return (0);
	(*options)->count = 0;
	(*options)->options = malloc(2 * sizeof(t_optype));
	if (!(*options)->options)
		return (free(*options), 0);
	err = get_opts_from_argv(argc, argv, &bench, &algo);
	if (err)
		return (err);
	if (bench == 1)
		(*options)->options[(*options)->count++] = BENCH;
	if (algo != UNKNOWN)
		(*options)->options[(*options)->count++] = algo;
	return ((*options)->count);
}
