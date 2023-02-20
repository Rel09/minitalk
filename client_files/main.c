/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/20 03:24:32 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_data *get_data() {
	static t_data T;
	return (&T);
}

int main(int argv, char **argc)
{
	if (argv != 3) {
		printf("Wrong input\n");
		return (1);
	}

	get_data()->server_id = ft_atoi(argc[1]);
	for (int i = 0; argc[2][i]; i++) {
		char_to_binary(argc[2][i]);
	}
	char_to_binary('\0');
	return (0);
}
