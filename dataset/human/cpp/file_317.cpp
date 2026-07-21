#include <bits/stdc++.h>

int main(void){
	int R,G,B,N;
	std::cin>>R>>G>>B>>N;

	int cnt = 0;
	for(int i=0;i<=N/R;i++){
		for(int j=0;j<=N/G;j++){
			int temp = N - i*R - j*G;
			if(temp%B == 0 && temp >= 0){
				cnt++;
			}
		}
	}
	
	std::cout<<cnt<<std::endl;
	return 0;
}
