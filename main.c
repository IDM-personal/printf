#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int val;

	val = 0;
	val = ft_printf("%7.5s", "yolo");
	printf("\nRETURN : %i",val);
	//printf("LAST LENGTH = %i \n",ft_printf("%s","10"));
	ft_printf("\n%s", NULL);
	printf("\n%s", NULL);
}
