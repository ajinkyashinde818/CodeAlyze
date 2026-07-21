#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int gcd(long long int a, long long int b){
  long long int t;
  while( b ) {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}

long long int powi(int a, long long int b) {
  return !b ? 1 : powi(a, b - 1) * a;
}

int main(void) {
  long long int i, j, ansi;
  char num[1000], temp[1000];
  scanf("%s",num);
  for(i = 0; num[i] != '.'; ++i) {
    temp[i] = num[i];
  }
  temp[i] = '\0';
  ansi = atoll(temp);
  if(strchr(num, (int)'(') == NULL) {
    long long int ansn;
    char tem[1000];
    for(j = i + 1; j < strlen(num); ++j) {
      tem[j - i - 1] = num[j];
    }
    tem[j] = '\0';
    ansn = atoll(tem);
    long long int ansu, ansa;
    ansu = powi(10, j - i - 1);
    ansa = ansn;
    long long int oo = gcd(ansu, ansa);
    ansu /= oo;
    ansa /= oo;
    ansa += ansu * ansi;
    printf("%lld/%lld\n",ansa, ansu);
  } else {
    long long int ansn, ansd;
    char tem[1000];
    for(j = i + 1; num[j] != '('; ++j) {
      tem[j - i - 1] = num[j];
    }
    ansn = atoll(tem);
    long long int ansu, ansa;
    ansu = powi(10, j - i - 1);
    ansa = ansn + ansi * ansu;
    for(i = j + 1; i < strlen(num) - 1; ++i) {
      tem[i - j - 1] = num[i];
    }
    tem[i - j - 1] = '\0';
    ansd = atoll(tem);
    long long tnuma, tnumu;
    tnumu = ansu * (powi(10, i - j - 1) - 1);
    tnuma = ansd;
    ansa = ansa * (powi(10, i - j - 1) - 1) + tnuma;
    ansu = tnumu;
    long long oo = gcd(ansa, ansu);
    ansa /= oo;
    ansu /= oo;
    printf("%lld/%lld\n",ansa, ansu);
  }
  return 0;
}
