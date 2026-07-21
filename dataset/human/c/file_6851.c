#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define N 100

int sum(int top, int under, int left, int right, int a[N][N], int temp);

int main(int argc, const char * argv[])
{
    int n=0;
    scanf("%d",&n);
    int a[N][N]={0};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    /*---------------*/
    
    
    int max = a[0][0];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=i; k<n; k++){
                int l=j;
                int temp=0;
                while(l<n){
                    temp=sum(i, k, j, l, a, temp);
                    if(temp>max){
                        max=temp;
                    }else if(temp<0){
                        l=n;
                    }
                    l++;
                }
            }
        }
    }
    
    /*---------------*/
    printf("%d\n",max);
}


int sum(int top, int under, int left, int right, int a[N][N], int temp){
    //int temp=0;
    for(int i=top; i<=under; i++){
        temp += a[i][right];
    }
    return temp;
}
