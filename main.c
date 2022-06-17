#include "philo.h"

void* foo(void* p)
{
	printf("Value recevied as argument in starting routine: ");
	printf("%i\n", * (int*)p);
	pthread_exit(NULL);
}

int parse_args(char **argv)
{
	int i;
	
	i = -1;
	while (argv[++i])
		ft_atoi(argv[i]);
}

int main(int argc, char **argv)
{
	if (parse_args(argv) || argc != 5 || argc != 6)
		error_msg("Check up your args!\n");
}