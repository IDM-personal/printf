#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		main()
{
	int val;

	val = 0;
	//printf("LAST LENGTH = %i \n",ft_printf("%s","10"));
	//val = ft_printf("%.*i", -6, -3);
	//printf("MYVAL %i\n",val);
	//val = printf("%.*i", -6, -3);
	//printf("MYVAL %i\n",val);
	//val = ft_printf("%0.6i", -3);
	//printf("MYVAL %i\n",val);
	val = ft_printf("%.5p", 0);
	printf("MYVAL %i\n",val);
	val = printf("%.5p", 0);
	printf("MYVAL %i\n",val);
	//val = printf("%.*i", -6, -3);
	//printf("MYVAL %i\n",val);
}
