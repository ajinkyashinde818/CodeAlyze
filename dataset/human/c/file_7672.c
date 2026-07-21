#include<stdio.h>

int data[10000];
int a;
int count = 0;

int main(void){
while(scanf("%d",&a) != EOF){
if (a == 0){
break;
}
data[count] = a;
count++;
}

for(int i = 0; i < count; i++){
printf("Case %d: %d\n",i+1,data[i]);
}
return 0;
}
