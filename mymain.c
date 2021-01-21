#include "ft_printf.h"

int main()
{
    printf("{%d}\n", printf("\033[1;32mTest 80 => \033[0m|%.d, %.0d|", 42, 42));
	ft_printf("{%d}\n", ft_printf("\033[1;31mTest 80 => \033[0m|%.d, %.0d|", 42, 42));
    printf("{%d}\n", printf("%.0i", 0));
	ft_printf("{%d}\n", ft_printf("%.0i", 0));
    printf("{%d}\n", printf("%.0d", 0));
	ft_printf("{%d}\n", ft_printf("%.0d", 0));
    
}
