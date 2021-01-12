#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	printf("LENGTH = %i \n",printf("10"));
	printf("LENGTH = %i \n",printf("%s%s","10","1"));
	printf("LENGTH = %i \n",ft_printf("10"));
	printf("LAST LENGTH = %i \n",ft_printf("%-1.10s","10"));
	//printf("LAST LENGTH = %i \n",ft_printf("%s","10"));
}
