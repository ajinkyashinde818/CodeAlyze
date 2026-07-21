#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int count=0;

    for(int r=0;r<=N;r++){
        for(int g=0;g<=N;g++){

            if(r*R+g*G<=N && (N-(r*R+g*G))%B==0){
                count++;
            }

            
            
        }
        
    }

    cout << count << endl;
}
