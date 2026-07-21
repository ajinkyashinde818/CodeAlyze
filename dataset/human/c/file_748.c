#include<stdio.h>
#define MOD 1000000007

typedef long long int lli;


#define kake(a,b) ( (a) *(b)%MOD)

int main(void){
  int n,i;
  scanf("%d",&n);
  char s[n];
  scanf("%s",s);
  int a[26]={};

  for(i=0;i<n;i++)
    a[s[i]-'a']++;
  lli num=1;
  for(i=0;i<26;i++){
    num=kake(num,a[i]+1);
  }

  printf("%ld",num-1);
 
  return 0;
}
