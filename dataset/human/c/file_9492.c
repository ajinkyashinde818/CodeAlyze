#include<stdio.h>

int main(){
int n,d,x,i,a,ans=0;
scanf("%d%d%d",&n,&d,&x);
for(i=0;i<n;i++){
scanf("%d",&a);
int j=0;
while(a*j+1<=d){
j++;
ans++;
}
}
printf("%d\n",ans+x);
return 0;
}
