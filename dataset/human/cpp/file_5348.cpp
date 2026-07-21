#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(){
  int n,r;
  scanf("%d %d\n",&n,&r);
  if(n<10){
    printf("%d\n",r+100*(10-n));
  }
  else{
    printf("%d\n",r);
  }
  return 0;
}
