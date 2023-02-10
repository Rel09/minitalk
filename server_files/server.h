/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:11:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/10 15:47:17 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct _data {
	int				i;
	char			str[100];
	struct _data	*next;
}	t_data;

typedef struct _recv {
	uint8_t i;
	char	data[9];
}	t_recv;

typedef struct _signal {
	uint8_t mode;
} t_signal;

t_recv 	*recv(void);//			- Grab the Received Data
t_data	*data(void);//			- Hold Linked List
#endif
