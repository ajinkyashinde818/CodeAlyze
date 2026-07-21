#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7ll;

int R,G,B,N;
int cnt;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>R>>G>>B>>N;

for(int r=0; r<=3000; r++){
	for(int g=0; g<=3000; g++){
		int n=N-(r*R+g*G);
		if(n<0) continue;
		else if(n==0) cnt++;
		else if(n%B==0) cnt++;
	}
}

cout<<cnt<<endl;

}
