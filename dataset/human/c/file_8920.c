#include<stdio.h>
 
int main(void){
 
int i,j,w,h,x = 1;
char b[52][52];
 
scanf("%d %d",&h,&w);
 
for(j = 1; j <= w; j++){
 for(i = 1; i <= h; i++){
scanf("%s",&b[i][j]);
 }
}
 
for(j = 1; j <= w; j++){
 for(i = 1; i <= h; i++){
if(b[i][j] == '#'){
if(b[i-1][j] == '#' || b[i+1][j] == '#' || b[i][j-1] == '#' || b[i][j+1] == '#') {}
else {x = 0; }
}
}
}
 
if(x == 1) printf("Yes");
else printf("No");
 
return 0;
}
