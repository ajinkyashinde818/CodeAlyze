#include<stdio.h>

int main(void){
  int E,Y;
  scanf("%d %d",&E,&Y);
  switch (E) {
    case 0:
      if(1<=Y-1868+1 && Y-1868+1<=44){ printf("M%d\n",Y-1868+1); }
      else if(1<=Y-1912+1 && Y-1912+1<=14){ printf("T%d\n",Y-1912+1); }
      else if(1<=Y-1868-1 && Y-1926+1<=63){ printf("S%d\n",Y-1926+1); }
      else{ printf("H%d\n",Y-1989+1); }
      break;
    case 1:
      Y+=1868-1;
      printf("%d\n",Y);
      break;
    case 2:
      Y+=1912-1;
      printf("%d\n",Y);
      break;
    case 3:
      Y+=1926-1;
      printf("%d\n",Y);
      break;
    case 4:
      Y+=1989-1;
      printf("%d\n",Y);
      break;
    default:
      break;
  }
  return 0;
}
