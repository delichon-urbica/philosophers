/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:52:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/01/19 16:54:58 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, t_data *data, char *str)
{
	if (check_dead_flag(data))
		return ;
	pthread_mutex_lock(&data->write_mutex);
	printf("%lu %i %s", (get_current_time() - data->start_time), 
		philo->philo_id, str);
	pthread_mutex_unlock(&data->write_mutex);
}

int	ft_usleep(t_data *data, size_t time)
{
	size_t	start;

	start = get_current_time();
	while (!check_dead_flag(data) && (get_current_time() - start) < time)
		usleep(500);
	if (check_dead_flag(data))
		return (1);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	digit_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
