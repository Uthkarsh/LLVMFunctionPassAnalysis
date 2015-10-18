#include <stdio.h>

extern void foo(float param);

extern void foo1(float param);

float correctDef(float check){

	return check;
}
int main() {

	foo(1.2f);
	foo1(1.5f);
	printf("%f",correctDef(324.32));
	printf("hello");
}
