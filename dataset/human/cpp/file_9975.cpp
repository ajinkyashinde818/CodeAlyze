#include <bits/stdc++.h>
using namespace std;
char alp[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int num_alp (char letter){
    return letter-'a';
}

int vec[26];

int main(){
    int M =pow(10,9)+7;
    int N; cin >> N;
    string S; cin >> S;

    for(int i=0; i<N; i++){
        vec[num_alp(S.at(i))]++;
    }

    long long ans =1;
    for(int i=0; i<26; i++){
        ans *= (vec[i]+1);
        ans = ans %M;
    }
    cout << ans-1 << endl;
}
