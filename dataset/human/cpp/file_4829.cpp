#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    long long int n,r;
    cin>>n>>r;
    if(n<10){
    	cout<<r+100*(10-n)<<endl;
    }
    else{
    	cout<<r<<endl;
    }
    return 0;
}
