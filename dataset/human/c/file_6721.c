#include<stdio.h>
int main(){
int ans=0,k=0,i,j,n,m,a[510][510],b,c,stack[101010],y[510];
while(1){
scanf("%d\n%d\n",&n,&m);
if(n==0 && m==0){
break;
}
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
a[i][j]=0;
}
}
for(i=0;i<=n;i++){
y[i]=0;
}
for(i=0;i<m;i++){
scanf("%d %d\n",&b,&c);
a[b][c]=1,a[c][b]=1;
}
for(i=1;i<=n;i++){
if(a[1][i]==1){
stack[k]=i;
y[i]=1,k++,ans++;
}
}
for(i=0;i<k;i++){
for(j=2;j<=n;j++){
if(a[stack[i]][j]==1 && y[j]==0){
ans++,y[j]=1;
}
}
}
printf("%d\n",ans);
ans=0,k=0;
}
return 0;
}
