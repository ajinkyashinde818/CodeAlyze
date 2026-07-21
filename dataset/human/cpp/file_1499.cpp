#include <bits/stdc++.h>

using namespace std;

int t;

int ap[100009];

int n;
int v[100][100];

void verif()
{
    for(int i = 1; i <= t; i ++)
    {
        if(ap[i] == 0)
            return;
    }

    int i, j;
    for(i = 1; i <= t; i ++)
    {
        for(j = i + 1; j <= t; j ++)
        {
            int com = 0;
            for(int h = 1; h <= ap[i]; h ++)
            {
                for(int l = 1; l <= ap[j]; l ++)
                {
                    if(v[i][h] == v[j][l])
                        com ++;
                }
            }

            if(com != 1)
                return;
        }
    }

    cout << t << "\n";
    for(i = 1; i <= t; i ++)
    {
        if(ap[i] != 0)
        {
            cout << ap[i] << "\n";
            for(int h = 1; h <= ap[i]; h ++)
                cout << v[i][h] << " " ;
            cout << "\n";
        }
    }

    exit(0);

    cout << "\n";
}

void bkt(int k)
{
    if(k == n + 1)
    {
        verif();

        return;
    }

    int i, j;
    for(i = 1; i <= t; i ++)
    {
        v[i][++ ap[i]] = k;
        for(j = i + 1; j <= t; j ++)
        {
            v[j][++ ap[j]] = k;
            bkt(k + 1);
            -- ap[j];
        }
        -- ap[i];
    }
}


int last[1000009];

vector <int> rez[100009];

void sol(int m)
{
    cout << m + 1 << "\n";

    int i, j;
    for(i = 1; i <= m; i ++)
    {
        ap[i] ++;
        rez[1].push_back(i);
        last[1] = 0;
    }

    int urm = m + 1;
    for(j = 2; j <= m + 1; j ++)
    {
        for(int x = 1; x < j; x ++)
        {
            rez[j].push_back(rez[x][last[x]]);
            ap[rez[x][last[x]]] ++;

            if(ap[rez[x][last[x]]] == 2)
                last[x] ++;
        }

        last[j] = j - 1;
        for(int x = j; x <= m; x ++)
        {
            rez[j].push_back(urm);
            ap[urm] ++;
            urm ++;
        }

    }

    for(i = 1; i <= m + 1; i ++)
    {
        cout << m << " ";
        for(auto u : rez[i])
            cout << u << " ";
        cout << "\n";
    }
}

int main()
{
    cin >> n;

    if(n == 1)
    {
        cout << "Yes\n";
        cout << "2\n1 1\n1 1\n";

        return 0;
    }

    int i;
    for(i = 2; i * (i + 1) <= 2 * n; i ++)
    {
        if(i * (i + 1) == 2 * n)
        {
            cout << "Yes\n";

            sol(i);

            return 0;
        }
    }

    cout << "No\n";
    return 0;

    t = (n << 1);

    for(t = 1; t <= (n << 1); t ++)
    {
        bkt(1);

        cout << t << "GATA\n";
    }

    return 0;
}
