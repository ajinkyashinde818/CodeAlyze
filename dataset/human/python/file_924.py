"""
カウンターの回り方はパターンが多すぎるので、考えない方がよい。
考え方１：
残っている寿司のうち、そこにたどり着くまでのエネルギー <= そこにたどり着くまでに摂取できる寿司のカロリー
となるような寿司があるかどうか。


考え方２：
二分探索。
X以上カロリーを得できるか、という二分探索。

考え方３：
動き方のパターンは4つある。
時計回りに動いて、どこかのタイミングで退店
半時計周りに動いて、どこかのタイミングで退店
時計回りに動いた後、反時計回りに動いて退店
反時計回りに動いた後、時計回りに動いて退店
それぞれのパターンで動く場合の最大価値を求める。
これで行こう
"""

N,C = map(int,input().split())
#sushi[i] => スタート地点から時計回りに動いたときにi番目にある寿司の情報
#sushiR[i] => スタート地点から反時計回りに動いたときにi番目にある寿司の情報
sushi = []
sushiR = []
for _ in range(N):
    x,v = map(int,input().split())
    sushi.append([x,v])
    sushiR.append([C-x,v])
sushiR = sushiR[::-1]

ans = 0
"""
まずは時計回りに動いてどこかのタイミングで退店する場合を考える。
これは、時計回りに寿司を見て行って、各寿司にたどり着いた時の、摂取カロリーの累積和と消費カロリーを求めればよい。
"""

cal = 0
for x,v in sushi:
    cal += v
    ans = max(ans,cal-x)

"""
次に反時計回りに動いてどこかのタイミングで退店する場合を考える。
"""
cal = 0
for x,v in sushiR:
    cal += v
    ans = max(ans,cal-x)


"""
時計回りに動いた後、反時計回りに動いて退店する場合を考える。
これは、時計回りでどこまで動くか（つまりどこで折り返すか）で場合わけし、
各地点で折り返す場合に、反時計回りでどこまで行くのがベストなのかをaccumSushiRをつかって判断する
"""
from heapq import heappop,heappush
sushiRQue = []
cal = 0
for i in range(N):
    x,v = sushiR[i]
    cal += v
    heappush(sushiRQue,(-(cal-x),i))

cal = 0
for i in range(N-1):
    x,v = sushi[i]
    cal += v
    while sushiRQue[0][1]+i >= N-1:
        heappop(sushiRQue)
    ans = max(ans,cal-x*2+(-sushiRQue[0][0]))

"""
時計回りに動いた後、反時計回りに動いて退店する場合を考える。
これは、時計回りでどこまで動くか（つまりどこで折り返すか）で場合わけし、
各地点で折り返す場合に、反時計回りでどこまで行くのがベストなのかをaccumSushiRをつかって判断する
"""
sushiQue = []
cal = 0
for i in range(N):
    x,v = sushi[i]
    cal += v
    heappush(sushiQue,(-(cal-x),i))

cal = 0
for i in range(N-1):
    x,v = sushiR[i]
    cal += v
    while sushiQue[0][1]+i >= N-1:
        heappop(sushiQue)
    ans = max(ans,cal-x*2+(-sushiQue[0][0]))

print(ans)
