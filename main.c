#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	printf("%5.1s\n","la cadena se pasa");
	printf("%10.5s\n","la cadena se pasa");
	printf("%*.*s\n",0,20,"la cadena se pasa");
	printf("%*.*c\n",0,20,'c');
	printf("debajo ft_printf");
	//ft_printf("%*.*s\n",0,20,"la cadena se pasa");
	printf("%5.1s\n","la cadena se pasa");
	printf("%5.1s\n","la cadena se pasa");
}
