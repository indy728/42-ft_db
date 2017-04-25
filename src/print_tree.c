/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:53:09 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/25 00:02:41 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	print_tree(t_list *begin_list)
{
	t_list	*scout;
	t_wine	*wine;

	if(begin_list)
	{
		scout = begin_list;
		while (scout->next)
		{
			wine = (t_wine *)scout->content;
			ft_printf("%d%10d%20s%10s\n", wine->key, wine->vintage,
					wine->region, wine->color);
			scout = scout->next;
		}
		wine = (t_wine *)scout->content;
		ft_printf("%d%10d%20s%10s\n", wine->key, wine->vintage,
				wine->region, wine->color);
	}
}
