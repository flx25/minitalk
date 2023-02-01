/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:13:09 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/02/01 11:08:26 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../minitalk.h"
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
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The Server PID is %i \n", (int) getpid());
	while (1)
		sleep(0);
}
