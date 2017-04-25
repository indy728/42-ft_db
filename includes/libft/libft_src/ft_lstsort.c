/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 03:41:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 03:48:48 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*cmp)(int, int))
{
	t_list	*begin_list;
	t_list	*hold;
	t_list	*scout;
	t_list	*trail;

	begin_list = *lst;
	scout = begin_list;
	while (scout->next)
	{
		hold = scout;
		scout = scout->next;
		if (begin_list == hold && !cmp(hold->data, scout->data))
		{
			begin_list = hold->next;
			hold->next = scout->next;
			scout->next = hold;
		}
		else if (!cmp(hold->data, scout->data))
		{
			trail->next = hold->next;
			hold->next = scout->next;
			scout->next = hold;
			scout = begin_list;
		}
		else
			trail = hold;
	}
	*lst = begin_list;
}
