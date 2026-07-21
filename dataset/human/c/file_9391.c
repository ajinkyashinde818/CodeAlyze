#include <stdio.h>

int main(){

int N,D,X;
int sum = 0;

scanf("%d",&N);
scanf("%d %d",&D,&X);


for(int i = 0; i<N;i++){


int A;
scanf("%d",&A);


for(int i = 0; i<D;i++){

int s = 1 + A*i;


if(s <= D){

 sum++;

}

}

}






int choco = sum + X;

printf("%d",choco);

}
