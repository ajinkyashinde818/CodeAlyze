#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;


int main() {
	int A, B;
	cin >> A >> B;
    if(A <= 10){
      cout << B + 100*(10-A) <<endl;
    }
    else{
      cout << B <<endl;
    }
	return 0;
}
