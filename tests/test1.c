#include <stdio.h>
/*void tester1(int);
void tester(int x)
{
printf("\nIn tester with value = %d",x);
tester1(x);

}
*/
void tester(short x)
{

	printf("\nInside tester");
}
int main() {
	int n;
	int sum;
	sum = 0;
	for (n = 0; n < 10; n++)
		sum = sum + n*n;
	printf("sum: %d\n", sum);
	float a=sum;
	int c=6;
	tester(a);
	tester(9.989);
	tester(c);
}
