#include <iostream>
#include <string>
using namespace std;

int abs(int x){
	if(x>0) return x;
	else return -x;
}

int main() {
    int N;
    cin >> N;

    int* a = new int[N];
    int index = 0;
    int minuscount = 0;
    for(int i=0;i<N;i++){
    	cin >> a[i];
    	if(abs(a[index]) > abs(a[i]) ){
    		index = i;
    	}
    	if(a[i] < 0) minuscount++;
    }

    long sum = 0;

    for(int i=0;i<N;i++){
    	if(i == index && minuscount % 2 == 1) sum -= abs(a[i]);
    	else sum += abs(a[i]);
    }
    cout << sum << endl;
  	
}
