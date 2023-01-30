/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:46:07 by fvon-nag          #+#    #+#             */
/*   Updated: 2023/01/30 10:25:13 by fvon-nag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int sendstring(int PID, char *str)
{

}

int	main(int argc, char **argv)
{
	int	PID;

	if (argc != 3)
		ft_printf("Please enter the server PID and a string to send!");
	else if (argv[1][0] == '\0')
		ft_printf("Please enter a correct PID!");
	else if (argv[2][0] == '\0')
		ft_printf("Please enter a string!");
	else
	{
		PID = ft_atoi(argv[1]);
		if (PID == 0)
			ft_printf("Please enter a correct PID!");
		else
			sendstring(PID, argv[2]);
	}
}
