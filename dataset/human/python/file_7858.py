import sys


def LI():
    return list(map(int, input().split()))


N, K, S = LI()
if K == 0:
    if S == 10**9:
        for i in range(N):
            print(1, end=" ")
    else:
        for i in range(N):
            print(10**9, end=" ")
    sys.exit()
for i in range(K):
    print(S, end=" ")
if S == 10**9:
    for i in range(N-K):
        print(S-1, end=" ")
else:
    for i in range(N-K):
        print(S+1, end=" ")
