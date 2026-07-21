#include <iostream>
using namespace std;
int main(void){
    int R,G,B,N;
    cin>>R>>G>>B>>N;
    int ans=0;
    for(int r=0;r*R<=N;r++){
        for(int g=0;g*G<=N;g++){
            if (N>=r*R+g*G){
                int b=(N-r*R-g*G)/B;
                if (r*R+g*G+b*B==N){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
