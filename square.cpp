//정수의 제곱을 계산하는 함수 예제
#include<stdio.h>
int square(int n);
int main(void)
{
	int i, result;
	for (i = 0; i < 5; i++)
	{
		result = square(i);
		printf("%d\n", result);
	}
	return 0;
}
int square(int n)
{
	return(n*n);
}