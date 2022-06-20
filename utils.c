#include "philo.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	if (str[i] == '-')
		error_msg("args cannot be negativ!\n");
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - '0');
		else
			error_msg("args contain only nums!\n");
		i++;
	}
	return (result);
}

void	unlock_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->data.number_of_philo)
	{
		pthread_mutex_unlock(&main->forks[i]);
		i++;
	}
}

long long	get_time(void)
{
	struct timeval time;
	
}

void error_msg(char *str)
{
	printf("%s", str);
	exit (0);
}