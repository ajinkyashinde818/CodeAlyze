#include <iostream>
using namespace std;
#include <map>
#include <string>
int main(){
	
    string s;
    long long N;
    cin >> N;
    cin >> s;

    map<long long,long long> m;

    for(long long i=0; i<s.size();i++){
        long long tmp = s[i] - 'a';
        m[tmp]++;
    }
    
    long long ans = 1;

    for(long long i=0;i<m.size();i++){
        long long  n = m[i];
        ans *=  (n+1);
        ans %=  1000000007;
    }

    cout << ans-1 << endl; 

}
