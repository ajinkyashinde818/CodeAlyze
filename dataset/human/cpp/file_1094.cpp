#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

int N;

int main(void) {
    int R,G,B;
    Int sum = 0;

    cin>>R>>G>>B>>N;

    for(int r = 0;r*R <= N;r++) {
        for(int g = 0;g*G <= N;g++) {
            if(r*R+g*G > N)
                break;
            int b = (N-r*R-g*G)/B;
            if(r*R+g*G+b*B == N) {
                sum++;
            }
        }
    }

    cout<<sum<<endl;

    return 0;
}
