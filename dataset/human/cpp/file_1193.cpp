#include <bits/stdc++.h>
 using namespace std ;

 int main () {

 int R,G,B,N;
 int sum,pair;
 cin >> R >> G >> B >> N ;

vector<int> v;
 v.push_back ( R );
 v.push_back ( G );
 v.push_back ( B );
 
 sort(v.begin(), v.end());

 R=v[2];
 G=v[1];
 B=v[0];

for(int r=0;r<=N/R;r++){
   for(int g=0;g<=(N-R*r)/G;g++){
       if((N-R*r-G*g)%B == 0)pair++;
     }
    
}
 cout << pair ;
 //cout << R << G << B;

 return 0;
 }
