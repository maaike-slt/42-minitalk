/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:48:37 by msloot            #+#    #+#             */
/*   Updated: 2024/04/19 17:19:53 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// need to test without usleep, if not work with smaller usleep
//	/!\ first finish the client before the test
// need to put that in minitalk.h most probably
#define SLEEP_TIME	420

int	main(int argc, char *argv[])
{
	long	pid;

	if (argc != 3)
		return (1);
	ft_putstr("client at PID: [");
	ft_putstr(Y_B_MAG);
	ft_putnbr(getpid());
	ft_putstr(Y_RESET);
	ft_putstr("] sends ");
	ft_putstr(Y_BOLD);
	ft_putstr(argv[2]);
	ft_putstr(Y_RESET);
	ft_putchar('\n');
	pid = ft_atoi(argv[1]);
	// send "yo\0"
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);

	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR2);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);

	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	kill(pid, SIGUSR1);
	usleep(SLEEP_TIME);
	return (0);
}