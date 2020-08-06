#include "./libft/libft.h"


int main()
{
	char *s = "3 2 1";
	int a[3] = {3, 2, 1};
	char **t = ft_strsplit_str(s);
	for(int i = 0; i < 3; i++)
		printf("%c", *t[0]);
}