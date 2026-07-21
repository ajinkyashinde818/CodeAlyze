#include<stdio.h>
#include<string.h>
int main()
{
int i;
int N;
int D1;
int D2;
int count=0;
int clear=0;
int flag=0;

scanf("%d",&N);
for(i=1;i<N+1;i++){
scanf("%d %d",&D1,&D2);
if(D1==D2 && count == 0 && clear==0 ){count=1; clear=1;}
else if(D1==D2 && count == 1 && clear==1 ){count=2;}  
else if(D1==D2 && count == 2 && clear==1 ){count=3;flag=1;}
else{ clear=0; count=0;}
}

if(flag==1){printf("Yes");}
else{printf("No");}
return 0;
}
