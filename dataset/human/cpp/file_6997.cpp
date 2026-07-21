#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5 + 3;
int n, mom[nmax], sol[nmax], t1, t2, t3, p;
vector <int> v1[nmax];
vector <int> v2[nmax];

struct usu1
{
    int x;

    bool operator < (const usu1 t) const
    {
        if(v1[x].size() < v1[t.x].size()) return 1;
        if(v1[x].size() > v1[t.x].size()) return 0;
        return x < t.x;
    }
};

struct usu2
{
    int x;

    bool operator < (const usu2 t) const
    {
        if(v2[x].size() < v2[t.x].size()) return 1;
        if(v2[x].size() > v2[t.x].size()) return 0;
        return (!(x < t.x));
    }
};

priority_queue <usu1> q1;
priority_queue <usu2> q2;

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> mom[i];

        v1[mom[i]].push_back(i);

        usu1 act;
        act.x = mom[i];

        if(mom[i] != mom[i - 1]) q1.push(act);
    }

    for(int i = 1; i <= n; ++i)
    {
        cin >> mom[i];

        v2[mom[i]].push_back(i);

        usu2 act;
        act.x = mom[i];

        if(mom[i] != mom[i - 1]) q2.push(act);
    }

    while(!q1.empty())
    {
        t1 = q1.top().x;
        q1.pop();

        t2 = q2.top().x;
        q2.pop();

        t3 = 0;

        if(!q2.empty())
        {
            t3 = q2.top().x;
            q2.pop();
        }

        if(t1 != t2)
        {
            p = v1[t1][v1[t1].size() - 1];
            sol[p] = t2;
            v1[t1].pop_back();
            v2[t2].pop_back();

            if(v1[t1].size() >= 1) q1.push({t1});
            if(v2[t2].size() >= 1) q2.push({t2});

            if(t3 != 0) q2.push({t3});
            continue;
        }

        q2.push({t2});

        if(t3 == 0)
        {
            cout << "No";
            return 0;
        }

        p = v1[t1][v1[t1].size() - 1];
        sol[p] = t3;
        v1[t1].pop_back();
        v2[t3].pop_back();

        if(v1[t1].size() >= 1) q1.push({t1});
        if(v2[t3].size() >= 1) q2.push({t3});
    }

    cout << "Yes\n";

    for(int i = 1; i <= n; ++i) cout << sol[i] << ' ';
    return 0;
}
