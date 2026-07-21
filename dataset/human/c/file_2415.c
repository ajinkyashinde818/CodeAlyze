#include <stdio.h>
int main(){
char str[3];
int a=0,b=0,c=0;
scanf("%s",str);
for(int i = 0;i < 3;i++){
if(str[i] == 'a')a++;
if(str[i] == 'b')b++;
if(str[i] == 'c')c++;
}
if(a==1&&b==1&&c==1){
printf("Yes");
}else{
printf("No");
}
return 0;
}
