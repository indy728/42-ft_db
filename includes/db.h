/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 00:30:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/24 19:15:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_H
# define DB_H

# include "libft.h"
# include <stdio.h>
# include <math.h>

# define MAX_REGION 20
# define MAX_COLOR	10

typedef struct	s_wine
{
	int			key;
	int			vintage;
	char		*region;	
	char		*color;
}				t_wine;

typedef enum	e_colors
{
	RED, WHITE, ROSE
}				t_colors;

typedef enum	e_region
{
	FR, CA, AUS
}				t_region;

#endif