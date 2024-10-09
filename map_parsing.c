/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:16:56 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/09 17:33:37 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_have_palyer;
int	is_have_exit;
int	is_have_collectible;
int	is_arround_wall;

char *test_line_map = "1111111111111";

void	parsing_map()
{
	while(!test_line_map)
	{
		if (!(*test_line_map == "0" || *test_line_map == "1" || *test_line_map == "C" || *test_line_map == "E" || *test_line_map == "P"))
			exit(1);
		
	}
}