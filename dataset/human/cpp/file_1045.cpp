#include <iostream>

int main(){

	int R, G, B, N;

	std::cin >> R >> G >> B >> N;

	int ans = 0;

	for(int i = 0; true; ++i){

		int r_amount = R * i;

		if(r_amount > N){
			break;
		}

		for(int j = 0; true; ++j){

			int rg_amount = r_amount + G * j;

			if(rg_amount > N){
				break;
			}

			if((N - rg_amount) % B == 0){
				++ans;
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
