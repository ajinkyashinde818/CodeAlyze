#include <stdio.h>
int main(void){
int gyo;
int a[100], b[100];

scanf("%d", &gyo);

int count = 0;
   
for(int i = 0; i < gyo; i++) {
    scanf("%d %d", &a[i], &b[i]);
  //  printf("%d %d\n", a[i], b[i]);
    
    if(a[i] == b[i]) {
    count = count + 1;
    }
    
    if(count >= 3)
    break;
    
    if(a[i] != b[i])
    count = 0;
   }

//printf("%d\n", count);

if(count >= 3)
printf("Yes");

else
printf("No");
   
   
}
