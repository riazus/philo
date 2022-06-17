#include "philo.h"

int ft_atoi(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}