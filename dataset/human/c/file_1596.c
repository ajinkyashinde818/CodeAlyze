#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  char s[1000000];
  char t[1000000];
  scanf("%s",s);
  int len = strlen(s);
  int n;
  int count=0;
  for(n=0;n<len;n++){
    if(s[n]!='x'){
      t[count] = s[n];
      count++;
    }
  }
  int left[100000]={};
  int right[100000]={};
  int left_p=0;
  int right_p=0;





  int flag = 1;
  for(n=0;n < count/2 ; n++){
    if(t[n] != t[count-1-n]){
      flag = 0;
    }
  }
  if(flag == 0){
    printf("-1");
  }
  else{
      for(n=0;n<len;n++){
        if(s[n]=='x'){
          left[left_p]++;
        }
        else{
          left_p++;
        }
      }
      for(n=len-1;n>=0;n--){
        if(s[n]=='x'){
          right[right_p]++;
        }
        else{
          right_p++;
        }
      }
      int sum=0;

      for(n=0;n<100000;n++){
        sum += (left[n] > right[n]) ? (left[n]-right[n]) : (right[n]-left[n]);
      }

      printf("%d",sum/2);
    }




}
