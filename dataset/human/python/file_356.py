import sys
sys.setrecursionlimit(10**6)
N = int(input())
Alist = list(map(int, input().split()))
memo = [{} for i in range(N)]

def ddp(cur_N, ai):
    if ai in memo[cur_N]:
        return memo[cur_N][ai]
    if cur_N >=N-1:
        return ai
    aj = Alist[cur_N+1]
    ret = max(ai + ddp(cur_N+1, aj), -1*ai + ddp(cur_N+1, -1*aj))
    memo[cur_N][ai] = ret
    return ret
print(ddp(0, Alist[0]))
