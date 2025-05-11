#include <stdio.h>
#include <stdbool.h>

bool ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int str_to_num(int num, char *str)
{
	int i;

	if (*str == '\0')
		return (num);
	if (!ft_isdigit(*str))
		return (-1);
	i = num * 10 + (*str - '0');
	return (str_to_num(i, ++str));
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf(" [%d] \n", str_to_num(0, argv[1]));
	}
	return (0);
}
