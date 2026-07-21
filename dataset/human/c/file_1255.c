#include<stdio.h>
#include<string.h>

int max(int a,int b){
  if(a>b) return a;
  else return b;
}

int min(int a,int b){
  if(a>b) return b;
  else return a;
}


int main(){
  char s[100],t[100];
  int box[100]={};
  int flag=0;
  int i,j;
  char temp;

  scanf("%s",s);
  scanf("%s",t);
  if(strlen(s)<strlen(t)){
    for(i=0;i<strlen(s);i++){
      for(j=0;j<strlen(t);j++){
        if(s[i]==t[j]&&box[j]==0){
          box[j]=1;
          flag=1;
          break;
        }
        else flag=0;
      }
      if(flag==0)  break;
    } 
  }
  if(flag==1) printf("Yes\n");
  else{
    for(i=0;i<strlen(s)-1;i++){
      for(j=i+1;j<strlen(s);j++){
        if(s[i]>s[j]){
          temp=s[i];
          s[i]=s[j];
          s[j]=temp;
       }
      }
    }
    for(i=0;i<strlen(t)-1;i++){
      for(j=i+1;j<strlen(t);j++){
        if(t[i]<t[j]){
          temp=t[i];
          t[i]=t[j];
          t[j]=temp;
       }
      }
    }
    if(strcmp(s,t)<0) flag=1;
    if(flag) printf("Yes\n");
    else printf("No\n");
  }
}
