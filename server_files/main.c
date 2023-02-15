/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:19 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/14 21:51:37 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_data	*data(void)
{
	static t_data T;
	return (&T);
}

t_recv	*recv(void)
{
	static t_recv T;
	return (&T);
}

t_size	*size(void)
{
	static t_size T;
	return (&T);
}

t_signal *mode(void)
{
	static t_signal T;
	return (&T);
}


int main (void)
{
	printf("Server Listening @ Process ID: [%i]\n", getpid());
	
	while (1)
	{
		// Wait for a connection
		while (mode()->mode == UNCONNECTED)
		{ 
			signal(SIGUSR1, listen_zero);
			signal(SIGUSR2, listen_one);
		}

		// If we're Connected / Waiting for data response
		while (mode()->mode == CONNECTED || mode()->mode == WAITING)
		{
			signal(SIGUSR1, recv_zero);
			signal(SIGUSR2, recv_one);
			printf("Connected\n");
		}
		
	}
	// Receive Data until we dont receive any anymore, then go back to UnConnected
	
	return 0;
}
