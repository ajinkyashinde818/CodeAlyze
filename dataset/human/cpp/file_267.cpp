#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int i,k;
  int count = 0;
  for(i=0;i<=N/R;i++)
    for(k=0;k<=(N-R*i)/G;k++)
      if((N-R*i-k*G)%B == 0) count++;
  cout << count << endl;
}
