#include <stdio.h>

int main() {
    int a,b,c,d;
    scanf("%d %d %d %d", &a,&b,&c,&d);
	int A = a * b;
    int B = c * d;
    if (A > B) printf("%d", A);
    else if (B > A) printf("%d", B);
    else if (A == B) printf("%d", A);
    
    return 0;
}
