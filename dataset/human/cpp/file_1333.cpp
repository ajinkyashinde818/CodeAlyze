#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

main(){
	int R,G,B,N;
	int ans=0;
	cin >> R >> G >> B >> N;
	for(int r=0;r<=N/R;r++){
		for(int g=0;g<=N/G;g++){
			if( (N-(r*R+g*G))%B==0 && (N-(r*R+g*G))>=0 ){
				ans++;
			}
		}
	}
	
	
	cout << ans <<endl;
}
