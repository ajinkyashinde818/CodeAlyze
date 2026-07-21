#include<stdio.h>

int main(){
int i,j;
char s[101],t[101];
scanf("%s %s",s,t);
for(i=0;s[i]!=0;i++){
for(j=0;j<i;j++){
if(s[i]<s[j]){
char tmp=s[i];
s[i]=s[j];
s[j]=tmp;
}
}
}

for(i=0;t[i]!=0;i++){
for(j=0;j<i;j++){
if(t[i]>t[j]){
char tmp=t[i];
t[i]=t[j];
t[j]=tmp;
}
}
}
i=0;
while(s[i]!=0&&t[i]!=0){
if(s[i]<t[i]){
puts("Yes");
return 0;
}
if(s[i]>t[i]){
puts("No");
return 0;
}i++;
}
for(i=0;s[i]!=0;i++);
for(j=0;t[j]!=0;j++);
if(i<j)puts("Yes");
else puts("No");
return 0;
}
