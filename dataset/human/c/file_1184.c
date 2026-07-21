#include<stdio.h>
#include<string.h>

int main(){
  
  char s[100],t[100];
  char temp;
  scanf("%s %s",s,t);

  int len_s,len_t;
  len_s = strlen(s);
  len_t = strlen(t);
  int count = 0;
  
  if(len_s > len_t){
    count = len_s;
  }else{
    count = len_t;
  }

//  printf("%d %d",len_s,len_t);

  for(int i=1; i<len_s; i++){
    for(int j=1; j<len_s; j++){
      if(s[j-1] > s[j]){
        temp = s[j-1];
        s[j-1] = s[j];
        s[j] = temp;
      }
    }
  }

  for(int i=1; i<len_t; i++){
    for(int j=1; j<len_t; j++){
      if(t[j-1] < t[j]){
        temp = t[j-1];
        t[j-1] = t[j];
        t[j] = temp;
      }
    }
  }

//  printf("%s\n%s\n",s,t);

  for(int i=0; i<count; i++){
    if(s[i] == '\0'){
      printf("Yes");
      return 0;
    }else if(t[i] == '\0'){
      printf("No");
      return 0;
    }

    if(s[i] < t[i]){
      printf("Yes");
      return 0;
    }else if(s[i] > t[i]){
      printf("No");
      return 0;
    }
  }

  printf("No");

}
