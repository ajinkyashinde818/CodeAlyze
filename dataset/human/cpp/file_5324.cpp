#include<iostream>
using namespace std;

int main(){
	int N,R;
	
	cin >> N;
	cin >> R;
	
	if(1>N || N>100 || 0>R || N>4111)exit(1);
	
	if(N>=10){
		cout << R << endl;
	}else{
		cout << R+((10-N)*100) << endl;
	}
	
return 0;
}
