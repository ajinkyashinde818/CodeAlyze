#include<stdio.h>
 
int main(){
 unsigned int K=0, S=0;
unsigned int count = 0;
 scanf("%d%d", &K, &S);
 for(unsigned int X = 0; X <= K; X++)
 for(unsigned int Y = 0; Y <= K; Y++)
 if(S - X - Y <= K) count ++;
 printf("%d\n", count);
}
