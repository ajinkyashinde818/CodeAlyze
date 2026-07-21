#include<bitset>
#include<iostream>
#include<string>
#include<utility>
#include<tuple>
#include<cmath>
#include<cstdio>
using namespace std;

typedef tuple<bool, int, int> P;

bitset<32> hex2binary(string& hex)
{
  unsigned long long v = stol(hex, nullptr, 16);
  return bitset<32>(v);
}

P kongo(const bitset<32>& binary)
{
  int v1 = 0;
  for(int i = 7; i < 31; i++)
    v1 += (int)pow(2, i - 7) * (int)binary[i];
  
  double v2 = 0;
  for(int i = 0; i < 7; i++)
    v2 += pow(0.5, 7 - i) * (int)binary[i];
  v2 *= 10000000;
  return P(binary[31], v1, (int)v2);
}

int main()
{
  int n; 
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    auto p = kongo(hex2binary(s));
    auto v1 = get<1>(p);
    auto v2 = get<2>(p);
    cout << (get<0>(p) ? "-" : "") << v1 << ".";
    for(int j = 0; j < 6 - (int)log10(v2); j++)
      cout << "0";
    while(v2 > 0 && !((int)v2 % 10))
      v2 /= 10;
    cout << v2 << endl;
  }
}
