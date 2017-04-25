/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/25 00:49:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"
#include <ctype.h>

/*
** Validate scanf input
*/

int main(int ac, char **av)
{
	int		choice;

	if (ac == 2)
	{
		while (1)
		{
			printf("Menu: \n");
			printf("1. Add a record\n");
			printf("2. Delete a record\n");
			printf("3. Search and display a record\n");
			printf("4. Sort and display all records\n");
			printf("5. Update a record\n");
			printf("6. Exit\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1:
					add(av[1]);
					break ;
				case 2:
					delete(av[1]);
					break ;
				case 5:
					update(av[1]);
					break ;
				case 6:
					exit (0);
				default:
					ft_printf("Please use keys 1 - 6 to make your choice.\n");
			}
		}
	}
	else
		ft_printf("USAGE: ./wine_db [wine database name]\n");
	return (0);
}
