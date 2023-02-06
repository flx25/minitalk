/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:13:09 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/02/06 15:07:02 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	handler(int sig, siginfo_t *client)
{
	static int	count;
	static int	sum;
	char		ascii;

	if (sig == SIGUSR1)
	{
		sum = (sum << 1) + ('0' - '0');
		count++;
	}
	if (sig == SIGUSR2)
	{
			sum = (sum << 1) + ('1' - '0');
			count++;
	}
	if (count == 8)
	{
		ascii = (char) sum;
		write (1, &ascii, 1);
		count = 0;
		sum = 0;
	}
	usleep(50);
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	ft_printf("The Server PID is %i \n", (int) getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = (void (*)(int))handler;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(0);
}
