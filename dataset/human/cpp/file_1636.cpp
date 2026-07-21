#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    vector<vector<long> > zz(2);
    zz[0].push_back(1);
    zz[1].push_back(1);

    if(n==1) {
        printf("Yes\n");
        printf("2\n");
        printf("1 1\n");
        printf("1 1\n");
        return 0;
    }

    long m=0;
    long k;
    for(k=2; k<=n*2; k++) {
        m+=(k-1);
        if(m>n) {
            break;
        }
        if(m==n) {
            printf("Yes\n");
            long i,j;
            printf("%ld\n", (long)zz.size());
            for(i=0; i<zz.size(); i++) {
                printf("%ld ", zz[i].size());
                for(j=0; j<zz[i].size(); j++) {
                    printf("%ld ", zz[i][j]);
                }
                printf("\n");
            }            
            return 0;
        }
        long sz=(long)zz.size();
        zz.push_back(vector<long>());
        long i;
        for(i=0; i<sz; i++) {
            zz[i].push_back(m+i+1);
            zz[sz].push_back(m+i+1);
        }
    }
    printf("No\n");

    return 0;
}
