#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    int N,A;
    int T[3];
    cin>>T[0]>>T[1]>>T[2]>>N;
    A=0;
    sort(T,T+3);
    reverse(T,T+3);
        
    
    for(int i=0;i<=N/T[0];i++){
        for(int j=0;j<=(N-i*T[0])/T[1];j++){
            
            if((N-T[0]*i-T[1]*j)%T[2]==0){
                    A=A+1;
                
            }    
        }
    }
    
    cout<<A<<endl;
    return 0;
    
}
