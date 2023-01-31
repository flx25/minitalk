/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:13:09 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/31 15:08:10 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../libft/libft.h"
#include "../../ft_printf/ft_printf.h"

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "0", 1);
	if (sig == SIGUSR2)
		write(1, "1", 1);
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("The Server PID is %i \n", (int) getpid());
	while (1)
		pause();
}
