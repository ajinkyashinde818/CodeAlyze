#include<iostream>

int main() {
	int R, G, B, N;
	std::cin >> R >> G >> B >> N;
	int r = N / R, g = N / G, b = N / B;
	int count = 0;
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= g; j++) {
			int a = N - i * R - j * G;
			if(a % B == 0 && a >= 0){
				count += 1;
			}
		}
		 
	}
	std::cout << count;
	return 0;
}
