#include<stdio.h>

int main(){
  int n = 0;
  char str[100001] = {};
  int i = 0;
  int now = 0;
  
  scanf(" %s",str);
  for(i=0;i<100001;i++){
    if(str[i] == '\0'){
      break;
    }
  }
  n = i;
  //printf("%d",n);
  now = n-1;
  while(now != -1){
    if(now >= 6 && str[now-6] ==  'd' && str[now-5] ==  'r' && str[now-4] ==  'e'
       &&   str[now-3] ==  'a' && str[now-2] ==  'm' && str[now-1] ==  'e' 
       &&   str[now] ==  'r'){
      now -= 7;
      //printf("A");
    }else if(now >= 5  && str[now-5] ==  'e' && str[now-4] ==  'r' 
             && str[now-3] ==  'a' && str[now-2] ==  's' && str[now-1] ==  'e' 
             && str[now] ==  'r' ){
      now -= 6;
      //printf("B");
    }else if(now >= 4  && str[now-4] ==  'e' && str[now-3] ==  'r' 
             && str[now-2] ==  'a' && str[now-1] ==  's' 
             && str[now] ==  'e'){
      //printf("C");
      now -= 5;
    }else if(now >= 4  && str[now-4] ==  'd' && str[now-3] ==  'r' 
             && str[now-2] ==  'e' && str[now-1] ==  'a' 
             && str[now] ==  'm'){
      //printf("D");
      now -= 5;
    }else{
      break;
    }
  }
  if(now == -1){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}
