#include<bits/stdc++.h>

using namespace std;
/*
const long long MaxSize = 1e5 + 17;
long long n;

long long solve(vector<long long>& v)
{
    vector<long long> answer(n, 0);

    answer[n / 2] = v[0];

    long long mmx = n - 1, mmn = 2;
    for(long long i = n / 2 + 1, j = 1; i < n; ++i, ++j)
    {
        if(j & 1)
        {
            answer[i] = v[mmx];
            mmx -= 2;
        }
        else
        {
            answer[i] = v[mmn];
            mmn += 2;
        }
    }


    for(long long i = n / 2 - 1, j = 1, mx = n - 2, mn = 1; i >= 0; --i, ++j)
    {
        if(j & 1)
        {
           // cout << mx << '\n';
            answer[i] = v[mx];

            if(mx - 2 < mmx)
                --mx;
            else
                mx -= 2;

        }
        else
        {
           // cout << mn << '\n';
            answer[i] = v[mn];

            mn += 2;

        }

    }

    long long ans = 0;


    for(long long i = 0; i < n; ++i)
        cout << answer[i] << ' ' ;
    cout << '\n';
    for(long long i = 1; i < n; ++i)
        ans += abs(answer[i] - answer[i - 1]);

    return ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<long long> v(n, 0);
    vector<long long> vv(n, 0);
    for(long long i = 0; i < n; ++i)
        cin >> v[i];

    for(long long i = 0; i < n; ++i)
        vv[i] = -v[i];

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    cout << max(solve(v), solve(vv)) << '\n';


}*/

main()
{
 //   ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

    long long n;
    cin >> n;

    long long nn = n * 2;

    for(long long i = 1; i * (i - 1) <= nn; ++i)
    {
        if(i * (i - 1) == nn)
        {
            cout << "Yes\n";

            cout << i << '\n';

            vector<vector<long long> > answer;

            vector<long long> v;

            for(long long j = 1; j <= i - 1; ++j)
                v.push_back(j);

            answer.push_back(v);


            long long last = i - 1;

            for(long long j = 1; j < i; ++j)
            {
                vector<long long> vv;
                for(long long k = 0; k < answer.size(); ++k)
                    vv.push_back(answer[k][j - 1]);

                for(long long k = answer.size(); k < i - 1; ++k)
                    vv.push_back(++last);

                answer.push_back(vv);
            }

            for(long long j = 0; j < answer.size(); ++j)
            {
                cout << answer[j].size() << ' ';
                for(long long k = 0; k < answer[j].size(); ++k)
                    cout << answer[j][k] << ' ';
                cout << '\n';
            }

            return 0;
        }
    }

    cout << "No\n";
}
