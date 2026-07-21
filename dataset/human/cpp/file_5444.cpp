#include<iostream>
using namespace std;
void optimize_cpp_stdio() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
}
int main(){
	optimize_cpp_stdio();
	int N, R;
	while(cin >> N >> R){
		if(N >= 10) cout << R << endl;
		else cout << R + 100 * (10 - N) << endl;
	} 
	return 0;
}
