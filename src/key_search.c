/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:47:39 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 23:49:30 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

t_list *key_search(t_list *begin_list, int key)
{
	t_list	*scout;
	t_wine	*wine;

	if (begin_list)
	{
		scout = begin_list;
		while (scout->next)
		{
			wine = (t_wine *)scout->content;
			if (wine->key == key)
				return (scout);
			scout = scout->next;
		}
		wine = (t_wine *)scout->content;
		if (wine->key == key)
			return (scout);
	}
	return (NULL);
}
