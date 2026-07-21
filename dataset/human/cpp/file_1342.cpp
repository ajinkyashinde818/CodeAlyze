#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef long long ll;


int main(){

ll R,G,B,N;

cin>>R>>G>>B>>N;

ll cnt;

for(int r=0;r<N+1;r++){
    if(N-r*R>0){
        for(int g=0;g<N+1;g++){
            if(N-r*R-g*G>0){
                
                    if((N-r*R-g*G)%B==0){
                        cnt++;
                    }             
            }
            else if(N-r*R-g*G==0){
                cnt++;
            }else if(N-r*R-g*G<0){
                break;
            }
        }
    }else if(N-r*R==0){
        cnt++;
    }else{
        break;
    }
}

cout<<cnt<<endl;

    return 0;

}
