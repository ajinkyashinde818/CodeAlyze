#include <iostream>
#include <vector>
#include <set>
#include <cmath>

typedef long long ll;

using namespace std;

int main(int argc , char *argv[]) {
    int R,G,B,N;
    int count=0;

    cin >> R >> G >> B >> N;

    for(int r=0 ; r<=N/R ; r++) {
        for(int g=0 ; g<=N/G ; g++) {
            int b=0;
            int inc = (N-r*R-g*G)/B;
            //cout << r << " " << g << " inc : " << inc << endl;
            if(r*R+g*G == N) count++;
            while(inc>0 && b<=N/B) {        
                if(r*R+g*G+b*B == N) count++;
                b+= inc;
            }
        }
    }

    cout << count;

    return 0;
}
