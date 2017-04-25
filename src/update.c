/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 23:23:49 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/25 00:52:22 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	update(char *file)
{
	int		fd;
	t_list	*begin_list;
	FILE	*fp;
	int		key;
	t_list	*scout;
	t_wine	*wine;
	char	*str;
	char	broke = 0;

	fd = open(file, O_RDONLY);
	get_tree(fd, &begin_list);
	print_tree(begin_list);
	str = ft_strnew(MAX_REGION);
	ft_printf("Enter the wine key you wish to update: ");
	scanf("%d", &key);
	if ((scout = key_search(begin_list, key)))
	{
		ft_printf("Is it, though?\n");
		wine = (t_wine *)scout->content;
		while (1)
		{
			ft_printf("%d\t%s\t%s\n", wine->vintage,
					wine->region, wine->color);
			ft_printf("Update menu: \n"
					"1. Change key\n"
					"2. Change vintage\n"
					"3. Change region\n"
					"4. Change color\n"
					"5. Exit\n");
			scanf("%d", &key);
			switch(key)
			{
				case 1:
					ft_printf("New key: \n");
					scanf("%d", &key);
					wine->key = key;
					break ;
				case 2:
					ft_printf("New vintage: \n");
					scanf("%d", &key);
					wine->vintage = key;
					break ;
				case 3:
					ft_printf("New region: \n");
					scanf("%s", str);
					ft_putendl(str);
					ft_strcpy(wine->region, str);
					break ;
				case 4:
					ft_printf("New color: \n");
					scanf("%s", str);
					ft_strcpy(wine->color, str);
					break ;
				case 5:
					fp = fopen(file, "w");
					serialize(fp, begin_list);
					fclose(fp);
					print_tree(begin_list);
					broke = 1;
					break ;
				default:
					ft_printf("Invalid key!\n");
					exit (1);
			}
			if(broke)
				break ;
		}
	}
	else
		ft_printf("Key not found.\n");
	
}
