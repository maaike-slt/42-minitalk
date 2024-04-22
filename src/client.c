/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:48:37 by msloot            #+#    #+#             */
/*   Updated: 2024/04/22 16:42:42 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// need to test without usleep, if not work with smaller usleep
//	/!\ first finish the client before the test
// need to put that in minitalk.h most probably
#define SLEEP_TIME 420

static void	ft_signal(int signum)
{
	(void)signum;
	ft_putstr("message has succesfully been sent\n");
}

static void	ft_send_byte(size_t pid, char c)
{
	unsigned char	i;

	i = 0;
	while (i <= 7)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(SLEEP_TIME);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	size_t	i;

	if (argc != 3)
		return (ft_puterr("wrong amount of arguments, three are needed\n"), 1);
	ft_putstr("client at PID: [");
	ft_putstr(Y_B_MAG);
	ft_putnbr(getpid());
	ft_putstr(Y_RESET);
	ft_putstr("] sends ");
	ft_putstr(Y_BOLD);
	ft_putstr(argv[2]);
	ft_putstr(Y_RESET);
	ft_putchar('\n');
	signal(SIGUSR1, ft_signal);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_send_byte(server_pid, argv[2][i]);
		i++;
	}
	ft_send_byte(server_pid, '\0');
	sleep(1);
	return (0);
}
