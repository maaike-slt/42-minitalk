/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:48:37 by msloot            #+#    #+#             */
/*   Updated: 2024/04/21 17:02:41 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 2)
		return (1);
	ft_putstr("PID: [");
	ft_putstr(Y_B_MAG);
	ft_putnbr(getpid());
	ft_putstr(Y_RESET);
	ft_putstr("]\n");
	pid = atoi(argv[1]);
}
