#include<iostream>

typedef long long ll;

using namespace std;

int main()
{ll R,G,B,N; cin >> R >> G >> B >> N;
 
 ll a = (N+R-1) / R; ll b = (N+G-1) / G ; ll c = (N+B-1) / b;
 
 ll cnt = 0;
 
 for(int i = 0; i <= a; i++){
   for(int j = 0; j <= b; j++){
       if( (N - i*R - j*G >= 0) && (N - i*R - j*G) % B == 0){ cnt++;}}}
 
 cout << cnt << endl;
 
 return 0;
}
