#include <bits/stdc++.h>
using namespace std;

int main(){
int R,G,B,N;
cin>>R>>G>>B>>N;
int ans = 0;
for(int r=0;r<N/R+1;r++){
for(int g=0;g<(N-R*r)/G+1;g++){
if( (N-R*r-G*g) < 0) continue;
if( (N-R*r-G*g)%B != 0) continue;

ans ++;
//cout<<r<< "  " <<g<<endl;
}
}
cout << ans << endl;
}
