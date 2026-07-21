#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int R,G,B,N;
	int count = 0;
	cin >> R >> G >> B >> N;
	for(int i = 0; i <= (N/R); i++){
		for(int j = 0; ((N-(i*R))/G) >= j ;j++){
			
			if((N-(i*R)-(j*G))%B == 0){
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
