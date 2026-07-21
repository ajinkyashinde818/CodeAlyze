#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cmath>
using namespace std;
int B[33], b;
void parse(long long x, int a){
  if ( 32 < a ) return;
  parse(x/2, a+1);
  B[b++] = x%2;
}

main(){
  int tcase; cin>> tcase;
  for ( int i = 0; i < tcase; i++ ){
    long long x;
    char tmp[20];
    string str;
    scanf("%llx", &x);
    b = 1;
    parse(x, 1);
    double d = 0;
    if ( B[1] ) cout << "-";
    for ( int i = 2, s = 23; i <= 25; i++, s-- ) d += (1<<s)*B[i];
    double r = 0.5;
    for ( int i = 26; i <= 32; i++, r /= 2 ) d += B[i]*r;
    sprintf(tmp, "%.10f", d);
    str = string(tmp);
    while( str.size() > 2 && str[str.size()-1] == '0' ) str.erase(str.end()-1);
    if ( str[str.size()-1] == '.' ) str += "0";
    cout <<  str << endl;
  }
}
