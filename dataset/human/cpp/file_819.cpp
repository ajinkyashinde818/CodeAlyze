#include <iostream>

using namespace std;

int R, G, B, N, r, g, b, ans;
int main()
{
    cin>>R>>G>>B>>N;

    r = N/R;
    g = N/G;
    b = N/B;

    for (int i=0; i<=r; i++)
        for(int j=0; j<=g; j++)
        {
            int k = (N-i*R-j*G);
            if (k>=0 && k%B==0) ans++;
        }
    cout<<ans;
}
