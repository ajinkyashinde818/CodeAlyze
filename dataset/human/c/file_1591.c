#include<stdio.h>
#include<string.h>

int main(void)
{
  char a[100010];
  int count=0;
  scanf("%s",a);
  int len=strlen(a);
  int j=0;

  int start=0,end=len-1;

  while(start<end){
    // printf("%d %d\n",start,end);
    if(a[start]==a[end]){
      start++;
      end--;
      //  puts("a");
    }else if(a[start]=='x'){
      count++;
      start++;
      //  puts("b");
    }else if(a[end]=='x'){
      count++;
      end--;
      // puts("c");
    }else{
      puts("-1");
      return 0;
    }
  }

  printf("%d\n",count);
  return 0;
}
