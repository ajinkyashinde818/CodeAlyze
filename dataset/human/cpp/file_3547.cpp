#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<long int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int num_odd_negative=0;
    int num_even_negative=0;
    for(int i=0;i<N;i++){
        if(A[i]<0){
            if(i%2==0){
            num_odd_negative+=1;
            }else{
                num_even_negative+=1;
            }
        }
    }
    long long int all_abs_sum=0;
    for(int i=0;i<N;i++){
        all_abs_sum+=std::abs(A[i]);
        A[i]=std::abs(A[i]);
    }

    if((num_even_negative+num_odd_negative)%2==0){
        cout<<all_abs_sum<<endl;
    }else{
        cout<<all_abs_sum-*std::min_element(A.begin(),A.end())*2<<endl;
    }
}
