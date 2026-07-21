#include<iostream>
#include<math.h>

using namespace std;

int main(void){
	
	int R,G,B,N;
	int count=0;
	
	cin>>R>>G>>B>>N;
	
	for(int i=0;i<=N/R;i++){
		for(int j=0;j<=N/G;j++){
			if(ceil((double)((double)(N-i*R-j*G)/B))==floor((double)((double)(N-i*R-j*G)/B)) && (N-i*R-j*G)/B>=0){
				count++;
			}
		}
	}
	
	cout<<count;
	
	return 0;
}
