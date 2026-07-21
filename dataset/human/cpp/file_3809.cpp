#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef long double LD;

class Circles
{
private:
    struct Circle
    {
        int x, y, r;
    };

    vector <Circle> v;
    LD dst[1005][1005];
    LD d[1005];

    LD getDistance(LD x11, LD y11, LD x22, LD y22)
    {
        LD ans = sqrt( (LD)1 * (x11 - x22) * (x11 - x22) + (LD)1 * (y11 - y22) * (y11 - y22) );
        return ans;
    }

    LD getDistance(Circle x, Circle y)
    {
        LD d = getDistance(x.x, x.y, y.x, y.y);
        d = max((LD)0.0, d - x.r - y.r);
        return d;
    }

    void calculateDistances()
    {
        for(int i = 0; i < v.size(); i++)
            for(int j = i + 1; j < v.size(); j++)
                dst[i][j] = dst[j][i] = getDistance(v[i], v[j]);
    }

public:
    void addCircle(int x, int y, int r)
    {
        Circle c;
        c.x = x;
        c.y = y;
        c.r = r;
        v.push_back(c);
    }

    LD getDistance(int st, int fn)
    {
        calculateDistances();

        for(int i = 0; i < v.size(); i++)
            d[i] = 2e18;

        queue <int> q;
        d[st] = 0.0;
        q.push(st);
        while(!q.empty())
        {
            int id = q.front();
            q.pop();

            for(int i = 0; i < v.size(); i++)
                if(d[i] > d[id] + dst[id][i])
                {
                    d[i] = d[id] + dst[id][i];
                    q.push(i);
                }
        }
        return d[fn];
    }
};

Circles crc;

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int x, y;
    scanf("%d%d", &x, &y);
    crc.addCircle(x, y, 0);
    scanf("%d%d", &x, &y);
    crc.addCircle(x, y, 0);

    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        crc.addCircle(x, y, r);
    }

    LD ans = crc.getDistance(0, 1);
    cout << fixed << setprecision(15) << ans;

    return 0;
}
