/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:27:19 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 23:59:38 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	delete(char *file)
{
	int		fd;
	t_list	*begin_list;
	FILE	*fp;

	fd = open(file, O_RDONLY);
	get_tree(fd, &begin_list);
	print_tree(begin_list);
	fp = fopen(file, "w");
	serialize(fp, begin_list);
	fclose(fp);
}
