/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:22:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 23:23:26 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void add(char *file)
{
	FILE	*fp;
	t_wine	*new;

	new = ft_memalloc(sizeof(t_wine));
	ft_bzero(new, sizeof(t_wine));
	new->region = ft_strnew(MAX_REGION);
	new->color = ft_strnew(MAX_COLOR);
	fp = fopen(file, "a+");
	if (fp != NULL)
	{
		printf("Enter number of key:\n");
		scanf("%d", &new->key);
		printf("Enter vintage:\n");
		scanf("%d", &new->vintage);
		printf("Enter region:\n");
		scanf("%s", new->region);
		printf("Enter color:\n");
		scanf("%s", new->color);
		fprintf(fp,"%d,%d,%s,%s\n", new->key, new->vintage, new->region, new->color);
	}
	else
	{
		printf("Error\n");
	}
	fclose(fp);
	free(new->region);
	free(new->color);
	free(new);
}
