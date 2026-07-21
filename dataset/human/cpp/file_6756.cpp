#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;

int main(){
    int N;
    cin>>N;

    int A[N];
    int B[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }

    int j=0;
    for(int i=0;i<N;i++){
        if(A[i]==B[i]){
            for(int c=0;c<N;j++,c++){
                if(A[i]!=B[j]&&A[j]!=B[i]){
                    swap(B[i],B[j]);
                    break;
                }
                if(j==N-1) j=-1;
            }
            if(A[i]==B[i]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<N;i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
}
