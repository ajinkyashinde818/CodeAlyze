def int_raw():
    return int(raw_input())

def ss_raw():
    return raw_input().split()

def ints_raw():
    return map(int,ss_raw())

INF = 1<<29

DIV = 10**9+7

def make2d_arr(w,h,val =INF):
    return [[val]*w for i in xrange(h)]

def floyd_warshall(costs):
    N = len(costs)
    for k in xrange(N):
        for i in xrange(N):
            for j in xrange(N):
                costs[i][j]  = min(costs[i][j],costs[i][k]+costs[k][j])
    return costs

N = int_raw()
S = raw_input()

dp = {}

for s in S:
    if not (s in dp):
        dp[s] = 1
    else:
        dp[s]+=1

ans =1

for k,v in dp.items():
    ans*=(v+1)
    ans % DIV


print (ans-1+DIV)% DIV
