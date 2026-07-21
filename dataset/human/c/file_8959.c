#include <stdio.h>
int main() {
int n, count;
scanf("%d",&n);
while(n != 0) {
count = 0;
while(n != 1) {
if(n % 2) {
n = n * 3 + 1;
} else {
n /= 2;
}
count++;
}
printf("%d\n",count);
scanf("%d",&n);
}
return 0;
}
