#include<stdio.h>

int main(void){
  char s[100001];
  int q,i,S;
  int t[200001],f[200001];
  char c[200001];
  int k=0;
  char b[200001],a[200001];
  int B=0;
  int A=0;
  
  scanf("%s\n%d",s,&q);
  for(i=0;i<=q-1;i++){
    scanf("\n%d",&t[i]);
    if(t[i]==2){
      scanf(" %d %c",&f[i],&c[i]);
    }
  }
  
  S=0;
  while(s[S]!=NULL){
    S++;
  }
  S=S-1;
  
  for(i=0;i<=q-1;i++){
    if(t[i]==1){
      k++;
    }else{
      if((k+f[i])%2==1){
        b[B]=c[i];
        B++;
      }else{
        a[A]=c[i];
        A++;
      }
    }
  }
  
  if(k%2==0){
    for(i=B-1;i>=0;i--){
      printf("%c",b[i]);
    }
    for(i=0;i<=S;i++){
      printf("%c",s[i]);
    }
    for(i=0;i<=A-1;i++){
      printf("%c",a[i]);
    }
  }else{
    for(i=A-1;i>=0;i--){
      printf("%c",a[i]);
    }
    for(i=S;i>=0;i--){
      printf("%c",s[i]);
    }
    for(i=0;i<=B-1;i++){
      printf("%c",b[i]);
    }
  }
  
  
  return 0;
}
