#include <iostream>
using namespace std;
int shou (int N,int R);
int ta (int N,int R); 
int main(void){
    int N,R;
    cin>>N>>R;
    if(N<10)cout<<shou(N,R)<<endl;
    else cout<<ta(N,R)<<endl;
    return 0;
}
int ta (int N,int R){
    return R;
}
int shou (int N,int R){
    return R+100*(10-N);
}
