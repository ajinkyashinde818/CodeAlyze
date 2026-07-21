#include <stdio.h>

int main(void)
{ int circumference,num;
 scanf("%d%d", &circumference, &num);
int number[num];
for(size_t i=0;i<num;++i){
scanf("%d",&number[i]);
}
int last = circumference-number[num-1]+number[0];

int b[num-1];
for (size_t i=0; i<num-1; ++i){

 b[i]=number[i+1]-number[i];
 }

 int largest=0;
 for (size_t i=0; i<num-1; ++i){
  if (b[i]>largest)
     largest=b[i];}
  if (last>largest)
   printf("%d", circumference-last);
  else
   printf("%d", circumference-largest);

return 0;
}
