#include<stdio.h>
int main(){
char s[4];
int i,a[100]={0};
scanf("%s",s);
for(i=0;i<3;i++){
a[s[i]]++;
}
if(a['a']==1&&a['b']==1&&a['c']==1){
printf("Yes\n");
return 0;
}
printf("No\n");
return 0;
}
