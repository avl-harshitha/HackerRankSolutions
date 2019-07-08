#include<stdio.h>

int addwoplus(int a, int b) {
    int sum = a ^ b;
    int carry = (a & b) << 1;
    if(carry == 0)
	    return sum;
    return addwoplus(sum, carry);
}

int main(int argc, char* argv[]) {
    printf("%d",addwoplus(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
