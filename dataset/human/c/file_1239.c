#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  char h[100],w[100];
  scanf("%s",h);
  scanf("%s",w);
  int a[strlen(h)],b[strlen(w)];
  for(int i=0;i<strlen(h);i++)a[i]=h[i];
  for(int i=0;i<strlen(w);i++)b[i]=w[i];
  for(int i=0;i<strlen(h);i++){
    int min=i;
    for(int j=0;j<strlen(h)-i;j++){
      if(a[min]>a[i+j])min=i+j;
    }
    int temp=a[i];
    a[i]=a[min];
    a[min]=temp;
  }
  for(int i=0;i<strlen(w);i++){
    int min=i;
    for(int j=0;j<strlen(w)-i;j++){
      if(b[min]<b[i+j])min=i+j;
    }
    int temp=b[i];
    b[i]=b[min];
    b[min]=temp;
  }
  //for(int i=0;i<strlen(h);i++)printf("%d ",a[i]);
  //for(int i=0;i<strlen(w);i++)printf("%d ",b[i]);

  int ab;
  if(strlen(h)>=strlen(w)){
    ab=strlen(w);
    for(int i=0;i<ab;i++){
      if(a[i]<b[i]){
        printf("Yes");
        return 0;
      }else if(a[i]>b[i]){
        printf("No");
        return 0;
      }
    }
    //if(strcmp(h,w)<0){printf("Yes\n");return 0;}
    printf("No");
    return 0;
  }
  else{
    ab=strlen(h);
  for(int i=0;i<ab;i++){
    if(a[i]<b[i]){
      printf("Yes");
      return 0;
    }
    else if(a[i]>b[i]){
      printf("No");
      return 0;
    }
  }
  if(strcmp(h,w)==0){printf("No");return 0;}
  printf("Yes");
}
}
