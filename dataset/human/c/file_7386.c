#include<math.h>
#include<stdio.h>
int main()
{
int a[10001]={0};int i=1;
while(i<10002){
    scanf("%d",&a[i]);if(a[i]==0)break ;
    i=i+1;
}
i=1;
while(a[i]!=0){printf("Case %d: %d\n",i,a[i]);i=i+1;}
return 0;
}
