#include <stdio.h>
int main(){
int n,a[31];
a[0]=0;
a[1]=1;
a[2]=2;
for(int i=3;i<=30;i++){
if(i%2==1)a[i]=a[i-1]*2+1;
else a[i]=(a[i-1]-a[i-1]/4)*2;
}
while(scanf("%d",&n)!=EOF){
printf("%d\n",a[n]);
}
}
