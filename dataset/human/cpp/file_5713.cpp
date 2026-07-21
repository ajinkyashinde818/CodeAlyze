#include <bits/stdc++.h>
using namespace std;

int N;
long long L;
vector<string>  s;
map<int, int> nims;

int main()
{
    cin >> N >> L;
    string prev, now;
    s.resize(N);
    for (int i=0; i<N; i++) cin >> s[i];
    sort(s.begin(), s.end());
    for (int i=0; i<s[0].size(); i++)
    {
        if (s[0][i] == '1')
        {
            nims[i]++;
        }
    }
    for (int j=1; j<N; j++)
    {
        prev = s[j-1];
        now = s[j];
        bool flag = false;
        for (int i=0; i<max(now.size(), prev.size()); i++)
        {
            if (flag)
            {
                if (prev.size() > i && prev[i] == '0') nims[i]++;
                if (now.size() > i && now[i] == '1') nims[i]++;
            }
            else
            {
                if (now[i] != prev[i]) flag = true;
            }
        }
    }
    for (int i=0; i<s[N-1].size(); i++)
    {
        if (s[N-1][i] == '0')
        {
            nims[i]++;
        }
    }
    int bool_ans = 0;
    for (auto nim : nims)
    {
        long long val = L - nim.first;
        if (val == 0 || (nim.second & 1) == 0) continue;
        int tmp=0;
        while ((val & 1) == 0)
        {
            val /= 2;
            tmp++;
        }
        bool_ans =  bool_ans ^ (1<<tmp);
    }
    if (bool_ans)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
    return 0;
}
