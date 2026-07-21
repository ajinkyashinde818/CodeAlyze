#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
  int n,ans,cnt;
   scanf("%d",&n);
  int i,j;
  int a[n];
  int b[n];

 
  for(j=0;j<n;j++){
    scanf("%d",&a[j]);
    scanf("%d",&b[j]);
  }
  ans=0;
  cnt=1;

  for(i=0;i<n-2;i++){
    if(a[i]==b[i]&&a[i+1]==b[i+1]&&a[i+2]==b[i+2]){
      puts("Yes");
      return 0;
    }
  }
  puts("No");
 return 0;
}
