#include <stdio.h>
int main()
{
	int a=-3;
	printf("%u %lu %ld ",a);
    printf("sizeof(char) = %lu\n", sizeof(char)); //1
    printf("sizeof(short) = %lu\n", sizeof(short));//2
    printf("sizeof(int) = %lu\n", sizeof(int));//4
    printf("sizeof(long) = %lu\n", sizeof(long));//8
}
