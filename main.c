/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:12:26 by msemenov          #+#    #+#             */
/*   Updated: 2018/02/16 11:12:27 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "filler.h"

void	ft_copy_map(char *line, t_data *data, int y)
{
	char *map_line;

	map_line = data->ptr_map[y];
	ft_strcpy(map_line, line + 3);
}

char *ft_fill_dot_map(char *map, t_data *data)
{
	int i;

	i = 0;
	while (i < data->map_len)
		map[i++] = '.';
	return (map);
}

char *ft_fill_dot_token(char *token, t_data *data)
{
	int i;

	i = 0;
	while (i < data->token_len)
		token[i++] = '.';
	return (token);
}

void	ft_check_player(char *line, t_data *data)
{
	int i;

	i = 0;
	if ((ft_strstr(line, "rtulchiy") != NULL))
	{
		while (line[i])
				if (line[i++] == 'p')
					data->player = line[i] - 48;
	}
}

void	ft_get_map(char *line, t_data *data)
{
	char **map;
	int i;

	i = 0;
	while (line[i])
		{
			if (ft_isdigit(line[i]))
			{
				data->map_hig = ft_atoi(&line[i]);
				i += 3;
			}
			if (ft_isdigit(line[i]))
				data->map_len = ft_atoi(&line[i++]);
			i++;
		}
		i = 0;
		map = (char**)malloc(sizeof(char*) * (data->map_hig + 1));
		map[data->map_hig] = NULL;
		while (i < data->map_hig)
		{
			map[i] = ft_strnew(data->map_len);
			map[i] = ft_fill_dot_map(map[i], data);
			i++;
		}
		data->ptr_map = map;
}

void	ft_copy_token(char *line, t_data *data)
{
	char *token_line;
	char *token;

	token_line = data->ptr_token[data->n];
	data->n++;
	ft_strcpy(token_line, line);

}

void	ft_get_token(char *line, t_data *data)
{
	char **token;
	int i;

	i = 6;
	while (line[i])
	{
			if (ft_isdigit(line[i++]))
			{
				data->token_hig = ft_atoi(&line[i]);
				break ;
			}
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]))
				data->token_len = ft_atoi(&line[i]);
			i++;
	}
		i = 0;
		token = (char**)malloc(sizeof(char*) * (data->token_hig + 1));
		token[data->token_hig] = NULL;
		while (i < data->token_hig)
		{
			token[i] = ft_strnew(data->token_len);
			token[i] = ft_fill_dot_token(token[i], data);
			i++;
		}
		data->ptr_token = token;
}

void	get_data(char *line, t_data *data)
{	
	char *Plateau;
	int i;

	i = 0;
	Plateau = "Plateau";
	if (*line == '$')
		ft_check_player(line, data);
	if (!ft_strncmp(line, Plateau, 7))
	{
		ft_get_map(line, data);
		data->n = 0;
	}
	if (ft_isdigit(*line))
		ft_copy_map(line, data, ft_atoi(line));
	 if (!ft_strncmp(line, "Piece", 5))
	 	ft_get_token(line, data);
	 if ((*line == '*' || *line == '.') && data->token_hig)
	 	ft_copy_token(line, data);
}

int	main(int argc, char const *argv[])
{
	int	fd;
	char *line;
	int i;
	char **token;
	t_data *data;
	data = ft_memalloc(sizeof(t_data));

	i = 0;
	fd = 0;
	while (get_next_line(fd, &line))
	{
		get_data(line, data);
		if (*line == 'q')
			break ;
	}
	char **line2 = data->ptr_map;
	while (*line2)
		printf("%s\n", *line2++);
	token = data->ptr_token;
	while(*token)
		printf("%s\n", *token++);
	printf("len = %d\n", data->map_len);
	printf("hig = %d\n", data->map_hig);
	printf("player = %d\n", data->player);
	return 0;
}