#include<stdio.h>
#include<string.h>

int len(char a[]){
  int i=0;

  while(a[i]!=0) i++;

  return i;
}

void sort(char a[],int n){
  int i,j;
  char c;

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
        c = a[j];
        a[j] = a[j-1];
        a[j-1] = c;
      }
    }
  }

}

void resort(char a[],int n){
  int i,j;
  char b;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]>a[j-1]){
        b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

int main(void){
  char a[1000];
  char b[1000];
  int i,n,m,c;

  scanf("%s %s",a,b);

  n = len(a);
  m = len(b);
  sort(a,n);
  resort(b,m);

  if(strcmp(a,b)<0) printf("Yes\n");
  else printf("No\n");

  return 0;
}
