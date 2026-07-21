#include <stdio.h>
int func(int a,int b,int c){
  int min = a>b?b:a;
  int array[99];
  int count = 0;
  for(int i = 1 ; i <= min ; i ++){
    if ((a % i == 0) && (b % i == 0)){
      array[count] = i;
      count ++;
    }
  }
  return array[count - c];

}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",func(a,b,c));
    return 0;
}
