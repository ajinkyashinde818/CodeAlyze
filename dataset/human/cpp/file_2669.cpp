#include <iostream>
#include <algorithm>

using namespace std;


static const int INF = (int)1e9;
static const int N=(int)1e5;


int main()
{
	int n;
    long long ans=0;
    int A[N];
    int cnt0min=0;
    int temp;
    long long sum=0;
    int minA=INF;

    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> A[i];
    }


    for(int i=0;i<n;i++){
        temp=abs(A[i]);
        if(A[i]<0)cnt0min++;
        minA=min(minA,temp);
        sum+=temp;
        
    }

    if(cnt0min%2==0){ans=sum;}
    else{ans=sum-minA*2;}

    cout << ans << endl;


	return 0;
}
