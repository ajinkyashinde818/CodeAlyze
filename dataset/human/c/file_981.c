#include <stdio.h>

void Seireki(int );
void Wareki(int ,int );

int main(void) {
  int E, Y;

  scanf("%d %d", &E, &Y);

  if(E == 0) Seireki(Y);
  else Wareki(E, Y);

  return 0;
}

void Seireki(int y) {
  if(y <= 1911) {
    printf("M%d", y-1867);
  } else if(y <= 1925) {
    printf("T%d", y-1911);
  } else if(y <= 1988) {
    printf("S%d", y-1925);
  } else {
    printf("H%d", y-1988);
  }

  printf("\n");
}

void Wareki(int e,int y) {
  switch(e) {
    case 1: printf("%d", y+1867);
            break;
    case 2: printf("%d", y+1911);
            break;
    case 3: printf("%d", y+1925);
            break;
    case 4: printf("%d", y+1988);
            break;
  }

  printf("\n");
}
