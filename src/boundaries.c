/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:14:22 by ego               #+#    #+#             */
/*   Updated: 2024/12/17 03:20:21 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes chunk boundaries for the first pass.
 *
 * @param bounds Boundaries struct to fill.
 * @param size Total stack size.
 * @param chunk Chunk divisor.
 */
void	init_boundaries(t_bounds *bounds, int size, int chunk)
{
	bounds->lower = 0;
	bounds->upper = size / chunk;
	bounds->size = size;
	return ;
}

/**
 * @brief Advances chunk boundaries to the next range.
 *
 * @param bounds Boundaries struct to update.
 * @param chunk Chunk divisor.
 */
void	update_boundaries(t_bounds *bounds, int chunk)
{
	bounds->lower = bounds->upper;
	bounds->upper = bounds->upper + (bounds->size - bounds->upper) / chunk;
	if (bounds->upper == bounds->lower)
		bounds->upper = bounds->lower + 1;
	return ;
}
