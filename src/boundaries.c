/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:14:22 by ego               #+#    #+#             */
/*   Updated: 2024/12/15 02:58:55 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	init_boundaries
*	Initializes the boundaries for the first chunk.
*/
void	init_boundaries(t_bounds *bounds, int size, int chunk)
{
	bounds->lower = 0;
	bounds->upper = size / chunk;
	bounds->size = size;
	return ;
}

/*	update_boundaries
*	Updates boundaries to those of the next chunk.
*/
void	update_boundaries(t_bounds *bounds, int chunk)
{
	bounds->lower = bounds->upper;
	bounds->upper = bounds->upper + (bounds->size - bounds->upper) / chunk;
	if (bounds->upper == bounds->lower)
		bounds->upper = bounds->lower + 1;
	return ;
}
