import sys
def input():
    return sys.stdin.readline()[:-1]

K,N = map(int,input().split(' '))
l = list(map(int, input().split()))

pre = l[0]
MAX = pre+K - l[-1]
for i in range(1,N):
    k = l[i]
    d = k - pre
    MAX = max(MAX,d)
    pre = k
print(K-MAX)
