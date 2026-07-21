#include <iostream>

using namespace std;

int N;
int S[26] = {0};


int main()
{
    cin >> N;
    char c;
    for (int i = 0;i < N; i++)
    {
        cin >> c;
        S[c-97]++;
    }

    long long int ans = 1;
    for (int i = 0; i < 26; i++)
    {
        if (S[i])
            ans = ans * (S[i]+1);

        if (ans >= 1000000007)
            ans %= 1000000007;
    }

    cout << ans -1;




    return 0;
}
