#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int val;

	val = 0;
	//printf("LAST LENGTH = %i \n",ft_printf("%s","10"));
	val = ft_printf("%-5%");
	printf("MYVAL %i\n",val);
	val = printf("%-5%");
	printf("MYVAL %i\n",val);
}
