#include <bits/stdc++.h>
    using namespace std;
	typedef long long int ll; 
     
    int main() {
        int N;
        cin >> N;
        //vector<ll> A(N);
        ll counter =0;
        ll sum =0; 
        ll A, M;
        M = 1000*1000*1000+7;
      
        for (int i = 0; i < N; i++) { 
       		 cin >> A; 
       		 if(A<0){
       		     counter++;
       		     A = -A; 
       		 }
       		 sum+=A;
       		 M=min(M,A);
        }   
        if(counter%2==0){
            cout<< sum << endl;
        }else{
            cout<< sum - 2*M << endl;
        }
   }
