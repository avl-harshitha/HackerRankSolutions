#include <stdio.h>

void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main() {
	int a, b;
	scanf("%d%d",&a,&b);
	printf("before swap a = %d, b = %d\n",a,b);
	swap(&a, &b);
	printf("after swap a = %d, b = %d\n",a,b);
	return 0;

}
