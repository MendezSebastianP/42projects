#include <stdio.h>
#include <string.h>

int	overlaptest(void *dest_str, const void *src_str, size_t n)
{
	const char	*src_start = src_str;
	const char	*src_end = src_str + n - 1;
	const char	*dest_start = dest_str;
	const char	*dest_end = dest_str + n - 1;

	if ((src_start <= dest_end) && (src_end >= dest_start))
		return (1);
	return (0);
}

int main (void) 
{
	char *str1 = "ABCDEF";

	int ret;

	for (int i = 0; i < 6; i++) {
	printf("str1[%d]: %p, str1[%d]: %p\n", i, (void*)&str1[i], i, (void*)&str1[i] + 2);
	}

	return 0;
}

