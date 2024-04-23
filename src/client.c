/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:48:37 by msloot            #+#    #+#             */
/*   Updated: 2024/04/23 21:16:56 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static bool	ft_check_pid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_arg(int argc, char *str, pid_t server_pid)
{
	if (argc != 3)
		return (ft_puterr("wrong amount of arguments, three are needed\n"),
			false);
	if (ft_check_pid(str) == false || server_pid > INT_MAX
		|| server_pid < 0)
		return (ft_puterr("invalid server PID\n"), false);
	return (true);
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	size_t	i;

	server_pid = ft_atoi(argv[1]);
	if (ft_check_arg(argc, argv[1], server_pid) == false)
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
	signal(SIGUSR1, ft_signal);
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
