#include<algorithm>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<map>
using namespace std;

int main(){

    int n,r;
    cin>>n>>r;


    //cout<<"running"<<endl;
    if(n>=10){
        cout<<r<<endl;
    }else{
        cout<<r+100*(10-n)<<endl;
    
    }

return 0;
}
