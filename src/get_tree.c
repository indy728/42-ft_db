/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:29:44 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 23:42:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static t_wine	*make_node(char **split)
{
	t_wine	*wine;

	wine = ft_memalloc(sizeof(t_wine));
	wine->key = ft_atoi(split[0]);
	wine->vintage = ft_atoi(split[1]);
	wine->region = split[2];
	wine->color = split[3];
	//wine->left = NULL;
	//wine->right = NULL;
	//wine->root = NULL;
	return (wine);
}

void	get_tree(int fd, t_list **begin_list)
{
	char	*line;
	char	**split;
	t_wine	*wine;

	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ',');
		wine = make_node(split);
		ft_lstadd_back(begin_list, ft_lstnew(wine, sizeof(t_wine)));
		free(split);
		free(wine);
	}
	ft_freezero(line, ft_strlen(line));
	close(fd);
}
