#include<bits/stdc++.h>
using namespace std;
int main()
{
  int Q;
  cin >> Q;
  while( Q-- ) {
    string s = "";
    for(int i=0; i<8; i++) {
      char c;
      cin >> c;
      if( c == '0' ) s += "0000";
      if( c == '1' ) s += "0001";
      if( c == '2' ) s += "0010";
      if( c == '3' ) s += "0011";
      if( c == '4' ) s += "0100";
      if( c == '5' ) s += "0101";
      if( c == '6' ) s += "0110";
      if( c == '7' ) s += "0111";
      if( c == '8' ) s += "1000";
      if( c == '9' ) s += "1001";
      if( c == 'a' ) s += "1010";
      if( c == 'b' ) s += "1011";
      if( c == 'c' ) s += "1100";
      if( c == 'd' ) s += "1101";
      if( c == 'e' ) s += "1110";
      if( c == 'f' ) s += "1111";
      // cout << s << endl;
    } 
 
    long long int sum = 0;
    long double sum2 = 0;
    for(int i=24; i>0; i--) {
      if( s[i] == '1' ) {
    sum += pow(2.0, 24-i);
      }
    }
    for(int i=25; i<32; i++) {
      if( s[i] == '1' ) {
    sum2 += pow(0.5, i-25+1);
      }
    }
    
    long long int tmp = (long long int)sum2;
    if( sum2 - (long double)tmp > 0 ) {
      if( s[0] == '1' ) {
    cout << '-';
      }
      string add = "";
      while( 1 ) {
    if( sum2 == 0 ) break;
    sum2 *= 10;
    tmp = (long long int)sum2;
    add += '0' + tmp;
    sum2 -= (long double)tmp;
      }
     
      cout << sum << '.' << add << endl;
    } else {
      if( s[0] == '1' ) {
    cout << '-';
      }
      cout << sum << ".0" << endl; 
    }
  }
   
}
