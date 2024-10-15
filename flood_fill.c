/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-hawa <aal-hawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:08:49 by aal-hawa          #+#    #+#             */
/*   Updated: 2024/10/15 19:34:32 by aal-hawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood(char **tab, t_point size, t_point cur, char to_flood)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y 
		|| tab[cur.y][cur.x] == to_flood || tab[cur.y][cur.x] == '1'
		|| (tab[cur.y][cur.x] == 'E' && to_flood == 's')
		|| (tab[cur.y][cur.x] == 'e' && to_flood == 'z'))
		return ;
	
	tab[cur.y][cur.x] = to_flood;
	flood(tab, size,(t_point){cur.x +1, cur.y}, to_flood);
	flood(tab, size,(t_point){cur.x -1, cur.y}, to_flood);
	flood(tab, size,(t_point){cur.x, cur.y - 1}, to_flood);
	flood(tab, size,(t_point){cur.x, cur.y + 1}, to_flood);
}

void  flood_fill(char **tab, t_point size, t_point begin, char to_flood)
{
	flood(tab, size, begin, to_flood);
}
