#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{int N; cin >> N;
 vector<long long> X(N);
 for(int i = 0; i < N ; i ++ )
 { cin >> X.at(i);}
 int cnt = 0;
 for ( int j = 0; j < N ; j++)
 {if( X.at(j) < 0 ) {cnt++;}}
 
 for(int i = 0; i < N; i++)
 {X.at(i) = abs( X.at(i));}
 
 //この時点でmainのカッコしかない
 if(cnt % 2 == 0 )
 {long long sum1 = 0;
  for(int i=0;i < N; i++)
  {sum1 += X.at(i);}
  cout << sum1<<endl;}
 //mainのみ
 else if(cnt % 2 != 0)
 {long long sum2 = 0; long long min_number = X.at(0);
  for(int i = 0; i < N ; i++)
  {min_number = min(min_number,X.at(i));}
  //min_number入力完了。この時点でelseとmainのみ。
  for (int i = 0; i < N; i++)
  {sum2 += X.at(i);}
  cout << sum2 - min_number*2 <<endl;}
 return 0;
}
