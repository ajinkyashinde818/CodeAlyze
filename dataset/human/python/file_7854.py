import sys,collections as cl,bisect as bs
sys.setrecursionlimit(100000)
input = sys.stdin.readline
mod = 10**9+7
Max = sys.maxsize
def l(): #intのlist
    return list(map(int,input().split()))
def m(): #複数文字
    return map(int,input().split())
def onem(): #Nとかの取得
    return int(input())
def s(x): #圧縮
    a = []
    aa = x[0]
    su = 1
    for i in range(len(x)-1):
        if aa != x[i+1]:
            a.append([aa,su])
            aa = x[i+1]
            su = 1
        else:
            su += 1
    a.append([aa,su])
    return a
def jo(x): #listをスペースごとに分ける
    return " ".join(map(str,x))
def max2(x): #他のときもどうように作成可能
    return max(map(max,x))
def In(x,a): #aがリスト(sorted)
    k = bs.bisect_left(a,x)
    if k != len(a) and a[k] ==  x:
        return True
    else:
        return False

def nibu(x,n,r):
    ll = 0
    rr = r
    while True:
        mid = (ll+rr)//2

    if rr == mid:
        return ll
    if x[mid] >= n:
        rr = mid
    else:
        ll = mid+1


N,K,S = m()


if N == K:
    print(jo([S for i in range(N)]))
else:
    if S % 2 == 0:
        if S != 10**9:
            print(jo([S//2 if i <= K else S+1 for i in range(N)]))
        else:
            print(jo([S//2 if i <= K else 1 for i in range(N)]))
    else:
        if S == 1:
            if S != 10**9:
                print(jo([S if i < K else S+1 for i in range(N)]))
            else:
                print(jo([S if i < K else S//2+1 for i in range(N)]))
        else:
            if S != 10**9:
                print(jo([(S//2+1 if i%2==0 else S//2) if i <= K else S+1 for i in range(N)]))
            else:
                print(jo([(S//2+1 if i%2==0 else S//2) if i <= K else S//3+1 for i in range(N)]))
