/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:13:09 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/02/02 09:48:33 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../minitalk.h"
#include "../../libft/libft.h"
#include "../../ft_printf/ft_printf.h"

char			*g_out; // maybe change this one to local

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

void	decrypt(void)
{
	int		len;
	int		i;
	int		j;
	char	ascii;
	int		sum;

	len = ft_strlen(g_out);
	i = 0;
	while (i < len - 8)
	{
		j = i;
		sum = 0;
		while (j < i + 8)
		{
			sum = (sum << 1) + (g_out[j] - '0');
			j++;
		}
		ascii = (char) sum;
		write(1, &ascii, 1);
		i += 8;
	}
	ft_memset(g_out, '0', len);
}

void	handler(int sig)
{
	static int	count;

	if (sig == SIGUSR1)
	{
		g_out = gnl_strjoin(g_out, "0");
		count++;
	}
	if (sig == SIGUSR2)
	{
			g_out = gnl_strjoin(g_out, "1");
			count = 0;
	}
	if (count == 8)
		decrypt();
}

int	main(void)
{
	struct sigaction	sa;
	int					state;

	sa.sa_handler = (void (*)(int))handler;
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("The Server PID is %i \n", (int) getpid());
	state = 1;
	while (1)
		sleep(0);
	ft_printf("convert string jetzt");
}
