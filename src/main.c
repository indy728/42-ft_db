/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 22:52:57 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void	print_list(t_list *begin_list)
{
	t_list	*scout;
	t_wine	*wine;

	if(begin_list)
	{
		scout = begin_list;
		while (scout->next)
		{
			wine = (t_wine *)scout->content;
			ft_printf("%d\t%s\t%s\n", wine->vintage,
					wine->region, wine->color);
			scout = scout->next;
		}
		wine = (t_wine *)scout->content;
		ft_printf("%d\t%s\t%s\n", wine->vintage,
				wine->region, wine->color);
	}
}

void	print_to_file(FILE *fp, t_list *begin_list)
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

t_wine	*make_node(char **split)
{
	t_wine	*wine;

	wine = ft_memalloc(sizeof(t_wine));
/*	if (!ft_strcmp(split[0], "red"))
		wine->color = RED;
	else
		wine->color = ft_strcmp(split[0], "white") ? ROSE : WHITE;
	if (!ft_strcmp(split[2], "FR"))
		wine->loc = FR;
	else
		wine->loc = ft_strcmp(split[2], "CA") ? AUS : CA;*/
	wine->key = ft_atoi(split[0]);
	wine->vintage = ft_atoi(split[1]);
	wine->region = split[2];
	wine->color = split[3];
	return (wine);
}

void	remove_end(t_list *begin_list/*, t_wine *copy*/)
{
	t_list	*scout;
	t_list	*hold;

	if (begin_list)
	{
		scout = begin_list;
		if (!scout->next)
			hold = scout;
		while (scout->next)
		{
			hold = scout;
			scout = scout->next;
		}
		hold->next = NULL;
		ft_lstdelone(&scout, ft_freezero);
	}
}

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

void	delete(char *file)
{
	int		fd;
	t_list	*begin_list;
	FILE	*fp;
	
	fd = open(file, O_RDONLY);
	get_tree(fd, &begin_list);
	print_list(begin_list);
	//remove_end(begin_list);
	fp = fopen(file, "w");
	print_to_file(fp, begin_list);
	fclose(fp);
}

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
	print_list(begin_list);
	str = ft_strnew(MAX_REGION);
	ft_printf("Enter the wine key you wish to update: ");
		scanf("%d", &key);
	if ((scout = key_search(begin_list, key)))
	{
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
					print_to_file(fp, begin_list);
					fclose(fp);
					print_list(begin_list);
					broke = 1;
					break ;
			}
			if(broke)
				break ;
		}
	}
	else
		ft_printf("Key not found.\n");
}

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
