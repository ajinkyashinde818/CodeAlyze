#include <stdio.h>

int sum(char, int);

int main(void){
  char scan[32], a[10], b[10], input_c;
  int loop, loop1, loop2, n, tmp = 0, mm, cc, xx, ii;

  fgets(scan, 20, stdin);
  n = atoi(scan);

  for(loop = 0; loop < n; loop++){
    for(loop1 = 0; loop1 < 32; loop1++){
      scan[loop1] = '\0';
    }

    fgets(scan, 32, stdin);

    for(loop1 = 0; scan[loop1] != ' '; loop1++){
      a[loop1] = scan[loop1];
    }
    a[loop1] = '\0';
    loop1++;
    for(loop2 = 0; scan[loop1] != '\n'; loop1++, loop2++){
      b[loop2] = scan[loop1];
    }
    b[loop2] = '\0';

    //    printf("%s\n%s\n", a, b);


    for(loop1 = 0; a[loop1] != '\0'; loop1++){
      if(a[loop1] == 'm')  tmp += 1000;
      else if(a[loop1] == 'c')  tmp += 100;
      else if(a[loop1] == 'x')  tmp += 10;
      else if(a[loop1] == 'i')  tmp += 1;

      else{
	tmp += sum(a[loop1 + 1], a[loop1] - 48);
	loop1++;
      }
    }
    //    printf("%d\n", tmp);
    for(loop1 = 0; b[loop1] != '\0'; loop1++){
      if(b[loop1] == 'm')  tmp += 1000;
      else if(b[loop1] == 'c')  tmp += 100;
      else if(b[loop1] == 'x')  tmp += 10;
      else if(b[loop1] == 'i')  tmp += 1;

      else{
	tmp += sum(b[loop1 + 1], b[loop1] - 48);
	loop1++;
      }
    }
    //    printf("%d\n", tmp);



    for(loop1 = 0; loop1 < 10; loop1++){
      a[loop1] = '\0';
    }
    loop1 = 0;

    mm = tmp / 1000;
    if(mm > 1){
      a[loop1] = mm + 48;
      loop1++;
    }
    if(mm > 0){
      a[loop1] = 'm';
      loop1++;
    }
    tmp -= mm * 1000;
    cc = tmp / 100;
    if(cc > 1){
      a[loop1] = cc + 48;
      loop1++;
    }
    if(cc > 0){
      a[loop1] = 'c';
      loop1++;
    }
    tmp -= cc * 100;
    xx = tmp / 10;
    if(xx > 1){
      a[loop1] = xx + 48;
      loop1++;
    }
    if(xx > 0){
      a[loop1] = 'x';
      loop1++;
    }
    tmp -= xx * 10;
    ii = tmp;
    if(ii > 1){
      a[loop1] = ii + 48;
      loop1++;
    }
    if(ii > 0){
      a[loop1] = 'i';
      loop1++;
    }

    printf("%s\n", a);


    tmp = 0;
    for(loop1 = 0; loop1 < 10; loop1++){
      a[loop1] = '\0';
      b[loop1] = '\0';
    }
    for(loop1 = 0; loop1 < 32; loop1++){
      scan[loop1] = '\0';
    }
  }


  return 0;

}


int sum(char c, int n){

  int result;

  if(c =='m') result = 1000* n;
  else if(c =='c') result = 100* n;
  else if(c =='x') result = 10* n;
  else result = 1* n;

  return result;

}
