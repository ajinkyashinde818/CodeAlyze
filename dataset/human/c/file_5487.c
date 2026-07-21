#include<stdio.h>
#include<math.h>

int main(){

bool N[10002];
//for(int i=0;i<10001;i++)
//N[i]=false;
int R[10003]={};
int H=2;

for(int i=3;H<=10001;i+=2)
{bool G=true;
for(int j=2;j<=sqrt((double)i);j++)
{if(i%j==0){G=false;break;}}
if(G==true){R[H]=i;H++;}
}

//N[2]=true;N[3]=true;
R[1]=2;R[0]=0;
int n;
while(1){

scanf("%d",&n);
if(n==0)break;
int s=0;
for(int i=1;i<=n;i++)
	s+=R[i];

printf("%d\n",s);
}
return 0;
}
