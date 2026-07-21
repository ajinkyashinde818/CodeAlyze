import bisect,collections,copy,heapq,itertools,math,numpy,string,decimal
import sys
def S(): return sys.stdin.readline().rstrip()
def I(): return int(sys.stdin.readline().rstrip())
def SS(): return map(str,sys.stdin.readline().rstrip().split())
def II(): return map(int,sys.stdin.readline().rstrip().split())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def LS(): return list(sys.stdin.readline().rstrip().split())
 
N,K = II()
A = LI()
flag = [False]*N
past = []
past.append(0)
now = 0
cnt = 1
for k in range(K):
  now = A[now]-1
  if flag[now]:
    past = past[past.index(now)::]
    print(past[(K - cnt) % len(past)]+1)
    exit()
  flag[now] = True
  cnt += 1
  past.append(now)
print(now+1)
