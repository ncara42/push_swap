/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freechunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvan-ach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:30:24 by vvan-ach          #+#    #+#             */
/*   Updated: 2026/01/02 18:06:54 by vvan-ach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freechunks(t_chunks *chunks)
{
	size_t	i;

	if (!chunks)
		return ;
	i = 0;
	while (i < chunks->count)
		free(chunks->chunks[i++]);
	free(chunks->chunks);
	free(chunks->sizes);
	free(chunks);
}
