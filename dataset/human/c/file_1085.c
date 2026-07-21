#include<stdio.h>
#include<string.h>
int Henkan(char *);
int main()
{
  int N,i,j,k,ST,n,NN;
  char S[100],T[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%s",S,T);
    ST=Henkan(S)+Henkan(T);
    for(j=3;j>=0;j--){
      NN=1;
      for(k=0;k<j;k++)NN*=10;
      N=ST/NN;
      if(N!=0 &&N!=1)printf("%d",N);
      if(j==0 && N!=0)printf("i"); 
      if(j==1 && N!=0)printf("x"); 
      if(j==2 && N!=0)printf("c"); 
      if(j==3 && N!=0)printf("m");
      ST=ST%NN;
    }
    printf("\n");
  }
  return 0;
}

int Henkan(char *ST)
{
  int i,sum=0,S[8]={0,1000,0,100,0,10,0,1};
  for(i=0;i<strlen(ST);i++){
    if(ST[i]=='m'){
      if(ST[i-1]>=49 &&ST[i-1]<=57){
	S[0]=ST[i-1]-'0';
      }
      else S[0]=1;
    }
    if(ST[i]=='c'){
      if(ST[i-1]>=49 &&ST[i-1]<=57){
	S[2]=ST[i-1]-'0';
      }
      else S[2]=1;
    }
    if(ST[i]=='x'){
      if(ST[i-1]>=49 &&ST[i-1]<=57){
	S[4]=ST[i-1]-'0';
      }
      else S[4]=1;
    }
    if(ST[i]=='i'){
      if(ST[i-1]>=49 &&ST[i-1]<=57){
	S[6]=ST[i-1]-'0';
      }
      else S[6]=1;
    }
  }
    
  for(i=0;i<8;i+=2)sum+=(S[i]*S[i+1]);
  return sum;
}
