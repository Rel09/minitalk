/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:55:38 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/10 11:55:09 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main (int argv, char **argc)
{
	if (!parser(argv, argc))
		return (0);
		
	printf("Received PID:		%i\n", data()->process_id);
	printf("Received String:	%s\n", data()->input_str);
	
	
	for (int i = 0; data()->input_str[i]; i++) {
		char_to_binary(data()->input_str[i]);
		printf("%c = %s\n", data()->input_str[i], data()->binary_str);
	}
	

	
	/*
	while (1) {
		kill(get_data()->process_id, SIGUSR1);
	}
	*/
	

	return 0;
}
