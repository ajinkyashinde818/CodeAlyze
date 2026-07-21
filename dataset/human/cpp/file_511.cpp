#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int R,B,G,N;
    cin>>R>>B>>G>>N;
    
    int k;
    int match = 0;
    for(int i =0;i<N+1;i++){
        for(int j=0; j<N-i+1;j++){
            k = N - i - j;
            if((i%R == 0) && (j%B == 0) && (k%G== 0)){
                match++;
            }
        }
    }
    cout<<match<<endl;
    return 0;
}
