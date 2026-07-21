//
// Created by sposa on 19.09.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   int arr[100][2];
   int n=0;
    int count = 0;
    scanf("%d",&n);
   for(int i= 0; i <n;i++ ){
       scanf("%d %d",&arr[i][0],&arr[i][1]);
   }

   for(int i = 0; i<n-2; i++){
    if(arr[i][0]==arr[i][1] && arr[i+1][0]==arr[i+1][1] && arr[i+2][0]==arr[i+2][1]){
        printf("Yes");
        return 0;
    }

   }
    printf("No");
    return 0;
}
