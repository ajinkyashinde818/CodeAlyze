#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

	int N;
	string S;

	cin >> N;
	S.reserve( N+1 );
	cin >> S;

    int count[26];

    for ( int i = 0; i < 26; i ++ ) count[i] = 0;

    for ( int i = 0; i < N; i ++ ) {
        for ( int j = 0; j < 26; j ++ ) {
            if ( S[i] == 'a'+j ) count[j] ++;
        }
    }

    unsigned long res = 1;
    for ( int i = 0; i < 26; i ++ ) {
        if ( count[i] == 1 ) res *= 2;
        if ( count[i] > 1 ) res *= (count[i]+1); // res *= 3;

        res --;
        if ( res > 1000000007 ) {
        	res %= 1000000007;
        }
        res ++;
    }
    res --;

    res %= 1000000007;
    cout << res << endl;


    return 0;
}
