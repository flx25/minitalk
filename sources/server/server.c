/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:13:09 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/02/01 11:44:02 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../minitalk.h"
#include "../../libft/libft.h"
#include "../../ft_printf/ft_printf.h"

void	handler(int sig, char *out)
{
	if (sig == SIGUSR1)
		out = gnl_strjoin(out, "0");
	if (sig == SIGUSR2)
		out = gnl_strjoin(out, "1");

	ft_printf("the binary string is %s", out);
}

char	*gnl_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*nstr;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	nstr = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (nstr == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			nstr[i] = str[i];
	while (buff[j] != '\0')
		nstr[i++] = buff[j++];
	nstr[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (nstr);
}

int	main(void)
{
	struct sigaction	sa;
	char				*out;

	out = ft_calloc(1, sizeof(char));
	sa.sa_handler = &handler;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The Server PID is %i \n", (int) getpid());
	while (1)
		sleep(0);
}
