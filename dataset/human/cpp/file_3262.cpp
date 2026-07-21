#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
  int N;
  cin >> N;

  vector<long> data;
  for(int i=0; i<N; i++)
  {
    int x;
    cin >> x;

    data.push_back(x);
  }

  long sum = abs(data[0]);
  int mindata = abs(data[0]);

  int negcnt;
  if(data[0] < 0) negcnt = 1;
  else negcnt = 0;

  int zeroFlag = 0;
  for(int i=1; i<N; i++)
  {
    long Ai = data[i];
    sum += abs(Ai);

    if(Ai<0) negcnt++;
    if(Ai == 0) zeroFlag = 1;

    if(mindata > abs(Ai)) mindata = abs(Ai);
  }

  if( (negcnt % 2 == 0) || zeroFlag ) cout << sum;
  else cout << sum - 2*(int)mindata;

  return 0;
}
