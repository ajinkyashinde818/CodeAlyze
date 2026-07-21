#include<bits/stdc++.h>
using namespace std;

int A, C, ans = 2e9;
vector<int> RGB(10);
vector<int> RG(10000);
int R, G, B, N;
int ok=0, flag=0;

vector<int> l(10, -1);

int main(){
    cin >> R >> G >> B >> N;
    int tmp;
    for(int i=0; i<=3000; i++){
	for(int j=0; j<=3000; j++){
	    tmp=N-R*i-G*j;
	    if((tmp>=0) && tmp%B==0){
		ok++;		
	    }
	    else if(tmp==0){
		ok++;
	    }
	}
    }
    

    // for(int k=0; k<RGB[2]; k++){
    // 	if(R*i+G*j+B*k==N)
    // 	    ok++;		
    // }


    cout << ok << "\n";
}
