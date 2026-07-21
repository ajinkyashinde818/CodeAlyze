#include<stdio.h>

int main(){
  int num_members, lim_height;
  scanf("%d %d", &num_members, &lim_height);
  
  int cnt = 0;
  int height_member;
  int i;
  for(i = 0; i < num_members; i++){
    scanf("%d", &height_member);
    if(height_member >= lim_height){
      cnt++;
    }
  }
  
  printf("%d", cnt);
}
