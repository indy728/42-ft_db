/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:50:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 23:51:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	serialize(FILE *fp, t_list *begin_list)
{
	t_list	*scout;
	t_wine	*wine;

	if(begin_list)
	{
		scout = begin_list;
		while (scout->next)
		{
			wine = (t_wine *)scout->content;
			fprintf(fp, "%d,%d,%s,%s\n", wine->key, wine->vintage,
					wine->region, wine->color);
			scout = scout->next;
		}
		wine = (t_wine *)scout->content;
		fprintf(fp, "%d,%d,%s,%s\n", wine->key, wine->vintage,
				wine->region, wine->color);
	}
}
