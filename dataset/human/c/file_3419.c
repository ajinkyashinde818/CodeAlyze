#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
  char S[100001];
  scanf("%s", S);

  bool isOk = false;
  bool isEnd = false;
  int tag = 0;
  int count = 0;

  while(!isEnd){
    if(tag == 0){
      if(S[count] == 'd'){
        tag = 1;
        count ++;
      }else if(S[count] == 'e'){
        tag = 11;
        count ++;
      }else if(S[count] == '\0'){
        isOk = true;
        break;
      }else{
        break;
      }
    }
    if(tag == 1){
      if(S[count] == 'r'){
        tag = 2;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 2){
      if(S[count] == 'e'){
        tag = 3;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 3){
      if(S[count] == 'a'){
        tag = 4;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 4){
      if(S[count] == 'm'){
        tag = 5;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 5){
      if(S[count] == 'e'){
        tag = 6;
        count ++;
      }else if(S[count] == 'd'){
        tag = 1;
        count ++;
      }else if(S[count] == '\0'){
        isOk = true;
        break;
      }else{
        break;
      }
    }
    if(tag == 6){
      if(S[count] == 'r'){
        tag = 7;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 7){
      if(S[count] == 'a'){
        tag = 13;
        count ++;
      }else if(S[count] == 'e'){
        tag = 11;
        count ++;
      }else if(S[count] == 'd'){
        tag = 1;
        count ++;
      }else if(S[count] == '\0'){
        isOk = true;
        break;
      }else{
        break;
      }
    }
    if(tag == 11){
      if(S[count] == 'r'){
        tag = 12;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 12){
      if(S[count] == 'a'){
        tag = 13;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 13){
      if(S[count] == 's'){
        tag = 14;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 14){
      if(S[count] == 'e'){
        tag = 15;
        count ++;
      }else{
        break;
      }
    }
    if(tag == 15){
      if(S[count] == 'r'){
        tag = 16;
        count ++;
      }else if(S[count] == 'd'){
        tag = 1;
        count ++;
      }else if(S[count] == 'e'){
        tag = 11;
        count ++;
      }else if(S[count] == '\0'){
        isOk = true;
        break;
      }else{
        break;
      }
    }
    if(tag == 16){
      if(S[count] == 'a'){
        tag = 13;
        count ++;
      }else if(S[count] == 'd'){
        tag = 1;
        count ++;
      }else if(S[count] == 'e'){
        tag = 11;
        count ++;
      }else if(S[count] == '\0'){
        isOk = true;
        break;
      }else{
        break;
      }
    }
  }

  if(isOk){
    printf("%s\n", "YES");
  }else{
    printf("%s\n", "NO");
  }

  return 0;
}
