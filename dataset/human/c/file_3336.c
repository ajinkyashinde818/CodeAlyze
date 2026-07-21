#include <stdio.h>
#include <string.h>
#define MAX 200000


int main(){
  
  char S[MAX];
  scanf("%s",S);
  int n = strlen(S), i;
  int flag = 1;
  for(i = n-1; i>=0;){
    if(S[i]=='m'){
      if(i<4){
        flag = 0;
        break;
      }
      if(S[i-4]!='d'||S[i-3]!='r'||S[i-2]!='e'||S[i-1]!='a'){
        flag = 0;
        break;
      }
      i -= 5;
    }else if(S[i]=='e'){
      if(i<4){
        flag = 0;
        break;
      }
      if(S[i-4]!='e'||S[i-3]!='r'||S[i-2]!='a'||S[i-1]!='s'){
        flag = 0;
        break;
      }
      i -= 5;
      
    }else if(S[i]=='r'){
      if(i<5){
        flag = 0;
        break;
      }
      if(S[i-1]!='e'){
        flag = 0;
        break;
      }
      if(S[i-2]=='s'){
        if(S[i-5]!='e'||S[i-4]!='r'||S[i-3]!='a'){
          flag = 0;
          break;
        }
        i -= 6;
      }else if(S[i-2]=='m'){
        if(i<6){
          flag = 0;
          break;
        }
        if(S[i-6]!='d'||S[i-5]!='r'||S[i-4]!='e'||S[i-3]!='a'){
          flag = 0;
          break;
        }
        i -= 7;
      }else {
        flag = 0;
        break;
      }
    }else{
      flag = 0;
      break;
    }
  }
  
  if(flag) puts("YES");
  else puts("NO");
  
  return 0;
}
