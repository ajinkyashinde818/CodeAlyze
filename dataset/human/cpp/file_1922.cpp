#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    unsigned int num = 0;
    for(int j = 0; j<8; j++){
      num <<= 4;
      if(isdigit(s[j])) num += s[j] - '0';
      else num += (s[j] - 'a') + 10;
    }
    int unit = 5000000;
    int sum = 0;
    for(int i=0; i<7; i++){
      if((num & (0x40 >> i)) != 0){
        sum += unit >> i;
      }
    } 
    char buf[8];
    sprintf(buf,"%07d",sum);
    int id = 6;
    while(id > 0 && buf[id] == '0') id--;
    buf[id+1] = '\0';
    if((num & 0x80000000) != 0) cout << "-";
    cout << ((num >> 7) & 0x00ffffff) << "." << buf << endl;
  }
  return 0;
}
