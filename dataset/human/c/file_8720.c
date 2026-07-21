#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MOD 1000000007
#define ll long long
 
int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
 
void swap(int *a, int *b);
 
int main(int argc, char **argv){
    int n,i;
    scanf("%d",&n);
    int a[n+1];
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    int j=0;
    int position=1;
    while(j<=n){
        j++;
        position = a[position];
        if(position==2){
            printf("%d\n",j);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
 
void swap(int *a, int *b){
    int tmp=*a;
    *a = *b;
    *b = tmp;
}
