/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:57:49 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/16 13:57:50 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data
{
	int			map_len;
	int			map_hig;
	int			token_len;
	int			token_hig;
	int			player;
	char**		ptr_map;
	char**		ptr_token;
	int			n;
}				t_data;

#endif