#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, n) for(int i=0;i<(int)(n);i++)

long lcm(long a, long b){
    long r, x, temp;
    x = a*b;
    if(a<b){
        temp = a;
        a = b;
        b = temp;
    }
    
    // Euclidean Algorithm 
    r = a%b;
    while(r != 0){
        a = b;
        b = r;
        r = a%b;
    }
    return x/b;
}

int main(void){
    long a, b, c;
    scanf("%ld%ld",&a,&b);
    c = lcm(a,b);
    printf("%ld\n",c);
    return 0; 
}
