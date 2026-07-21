#include<stdio.h>
#include<string.h>
int main(void){
  
char s[100001];
  scanf("%s",&s);
  int len=strlen(s);
  char ss[500001];
  
  for(int i=200000;i<len+200000;i++){
    ss[i]=s[i-200000];
    //printf("%c",ss[i]);
  }
  //printf("\n");
 int top=200000;
 int tail=200000+len-1;
  
  int q;
  scanf("%d",&q);
  int t[q+1],f[q+1];
  char c[q+1];
  for(int i=0;i<q;i++){
scanf("%d",&t[i]);
    if(t[i]==2){
      scanf("%d %c",&f[i],&c[i]);
    }
   // printf("t[%d]=%d,f[%d]=%d,c[%d]=%c\n",i,t[i],i,f[i],i,c[i]);
  }
     
  int flag=0;  // flag=0:順方向,flag=1:逆方向
  for(int i=0;i<q;i++){
    //printf("%d回目\n",i);
    if(t[i]==1){//反転
      flag=1-flag;
    /* for(int j=0;j<len/2;j++){
      char w=s[j];
       s[j]=s[len-1-j];
       s[len-1-j]=w;
    }*/
    }
    
    if(t[i]==2){
      if(f[i]==1){  //先頭に挿入	
        if(flag==0){
          top--;
          ss[top]=c[i];
        }
         else {
           tail++;
           ss[tail]=c[i];
         }
      }
      else if(f[i]==2){
        if(flag==0){
          tail++;
           ss[tail]=c[i];
        }
        else{
          top--;
          ss[top]=c[i];
        }
      }
    }
  }
     if(!flag){
       for(int i=top;i<=tail;i++){
         printf("%c",ss[i]);
       }
     }
    else {
      for(int i=tail;i>=top;i--){
        printf("%c",ss[i]);
       }
     }
  
    return 0;
  }
