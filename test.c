#include <unistd.h>
#include <stdio.h>

int isbaseok(char *base)
{
    char *used[ft_strlen(base)];
    int i;
    int j;
    int usedcont;

    usedcont = 0;
    j = 0;
    i = 0;
    if (ft_strlen(base) <= 1)
        return (-1);
    while (i != ft_strlen(base))
    {
        if (base[i] == 43 || base[i] == 45)
            return (-1);
        j = 0;
        while (j != 5)
        {
            if (base[i] == used[j])
                return (-1);
            j++;
        }
        used[usedcont++] = base[i];
        i++;
    }
    return (1);
}

void formalcreator(int nbr, char *base, int len)
{
    if ((nbr / len) > len)
    {
        formalcreator((nbr / len), base, len);
        write(1, &base[(nbr % len)], 1);
    }
    if ((nbr / len) < len)
    {
        if (nbr / len > 0)
            write(1, &base[(nbr / len)], 1);
        write(1, &base[(nbr % len)], 1);
    }
}

void ft_putnbr_base(int nbr, char *base)
{
    if (isbaseok(base) == 1)
    {
        if (nbr < 0)
        {
            write(1, "-", 1);
            nbr *= -1;
        }
        formalcreator(nbr, base, strlen(base));
    }
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int main()
{
    ft_putnbr_base(280002,"0123456789abcedf");
    return (0);
}