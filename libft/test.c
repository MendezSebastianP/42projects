int	splitlen(char const *s1, char c1)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i])
	{
		while (s1[i] == c1 && s1[i])
			i++;
		if (s1[i])
			k++;
		while(s1[i] != c1 && s1[i])
			i++;
	}
	return (k);
}
#include <stdio.h>
int main(int c, char *v[])
{
	(void)c;
	printf("result: %d", splitlen(v[1],v[2][0]));
	return (0);
}