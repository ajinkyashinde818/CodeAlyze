#include<stdio.h>
int main(){
int list[2][10000];
int friend[500];
int friendoffriend[500];
int n,m,i,j,count;
while(1){
scanf("%d",&n);
scanf("%d",&m);
if(n==0&&m==0) return 0;
for(i=0;i<500;i++){
friend[i]=0;
friendoffriend[i]=0;
}
count=0;
for(i=0;i<m;i++){
scanf("%d %d",&list[0][i],&list[1][i]);
if(list[0][i]==1) friend[list[1][i]-1]=1;
if(list[1][i]==1) friend[list[0][i]-1]=1;
}
for(i=1;i<n;i++){
if(friend[i]>0){
for(j=0;j<m;j++){
if(list[0][j]==i+1) friendoffriend[list[1][j]-1]=1;
if(list[1][j]==i+1) friendoffriend[list[0][j]-1]=1;
}
}
}
for(i=1;i<n;i++) if(friend[i]>0||friendoffriend[i]>0) {
count++;
}
printf("%d\n",count);
}
}
