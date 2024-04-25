/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:44:53 by msloot            #+#    #+#             */
/*   Updated: 2024/04/25 21:36:41 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
// for usleep aparently, need to test at school
# define _DEFAULT_SOURCE
# define BUFFER_SIZE 1024
# define SLEEP_TIME 350

# include "../libft/inc/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

#endif